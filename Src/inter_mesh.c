/*
** inter_mesh.c for rt in /home/miele_t//TP/igraph/RayTracer/RT
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Wed Apr 25 12:42:42 2012 thomas miele
** Last update Sat Jun  2 15:01:12 2012 thomas miele
*/

#include <stdlib.h>
#include "Include/my_mlx.h"
#include "Include/struct.h"
#include "Include/raytracer.h"
#include "Include/color.h"
#include "Include/luminosite.h"
#include "Include/mesh.h"

/*
** pov : point of view: Camera or P point.
** ray : vector V (camera vector) or vector L (light vector)
** obj : mesh for raytracing, spot for luminosite
** ray->bool : 1 for camera intersection
**             0 for spot intersection
*/

int     inter_choice(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  int   ret;

  if (obj->type == PLAN)
    ret = inter_plan(pov, obj, ray);
  else if (obj->type == SPHERE)
    ret = inter_sphere(pov, obj, ray);
  else if (obj->type == CYLINDRE)
    ret = inter_cylindre(pov, obj, ray);
  else if (obj->type == CONE)
    ret = inter_cone(pov, obj, ray);
  else
    exit(EXIT_FAILURE);
  return (ret);
}

int		inter_plan(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  float		k;
  float		V[3];

  V[0] = ray->Vx - obj->obj.pos.X;
  V[1] = ray->Vy - obj->obj.pos.Y;
  V[2] = ray->Vz - obj->obj.pos.Z;
  if (ray->bool)
    {
      rotate_x(&V[0], &V[1], &V[2], -(obj->obj.rot.X));
      rotate_y(&V[0], &V[1], &V[2], -(obj->obj.rot.Y));
      rotate_z(&V[0], &V[1], &V[2], -(obj->obj.rot.Z));
    }
  if (V[2] == 0.0)
    return (0);
  k = -(pov->pos.Z) / V[2];
  ray->K = k;
  ray->color = obj->obj.color;
  if (ray->bool)
    get_plan(pov, obj, ray);
  if (k >= 0)
    return (1);
  else
    return (0);
}

int		inter_sphere(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  int		ret;
  float		k;

  calc_sphere(pov, obj, ray);
  if (obj->obj.calc.delta >= 0)
    {
      ret = calc_k(obj, &k);
      if (ret == 1)
	{
	  ray->K = k;
	  ray->color = obj->obj.color;
	  if (ray)
	    get_sphere(pov, obj, ray);
	  return (1);
	}
      else
	return (0);
    }
  else
    return (0);
}

int		inter_cylindre(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  int		ret;
  float		k;

  calc_cylindre(pov, obj, ray);
  if (obj->obj.calc.delta >= 0)
    {
      ret = calc_k(obj, &k);
      if (ret == 1)
	{
	  ray->K = k;
	  ray->color = obj->obj.color;
	  if (ray)
	    get_cylindre(pov, obj, ray);
	  return (1);
	}
      else
	return (0);
    }
  else
    return (0);
}

int		inter_cone(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  int		ret;
  float		k;

  calc_cone(pov, obj, ray);
  if (obj->obj.calc.delta >= 0)
    {
      ret = calc_k(obj, &k);
      if (ret == 1)
	{
	  ray->K = k;
	  ray->color = obj->obj.color;
	  if (ray)
	    get_cone(pov, obj, ray);
	  return (1);
	}
      else
	return (0);
    }
  else
    return (0);
}
