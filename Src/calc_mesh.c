/*
** calc_mesh.c for rt in /home/miele_t//TP/igraph/RayTracer/RT
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Wed May 16 11:28:17 2012 thomas miele
** Last update Sun Jun  3 17:09:36 2012 thomas miele
*/

#include <stdlib.h>
#include <math.h>
#include "Include/my_mlx.h"
#include "Include/struct.h"
#include "Include/raytracer.h"
#include "Include/color.h"
#include "Include/luminosite.h"
#include "Include/mesh.h"

int	calc_k(t_llist *obj, float *k)
{
  if (obj->obj.calc.k1 < 0 && obj->obj.calc.k2 < 0)
    return (0);
  if (obj->obj.calc.k1 >= 0 && obj->obj.calc.k2 < 0)
    *k = obj->obj.calc.k1;
  if (obj->obj.calc.k1 < 0 && obj->obj.calc.k2 >= 0)
    *k = obj->obj.calc.k2;
  if (obj->obj.calc.k1 >= 0 && obj->obj.calc.k2 >= 0)
    {
      if (obj->obj.calc.k1 >= obj->obj.calc.k2)
	*k = obj->obj.calc.k2;
      if (obj->obj.calc.k2 >= obj->obj.calc.k1)
	*k = obj->obj.calc.k1;
      return (1);
    }
}

void	calc_sphere(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  t_calc tmp;
  float	V[3];
  float	Cam[3];

  V[0] = ray->Vx - obj->obj.pos.X;
  V[1] = ray->Vy + obj->obj.pos.Y;
  V[2] = ray->Vz - obj->obj.pos.Z;
  if (ray->bool)
    {
      rotate_x(&V[0], &V[1], &V[2], -(obj->obj.rot.X));
      rotate_y(&V[0], &V[1], &V[2], -(obj->obj.rot.Y));
      rotate_z(&V[0], &V[1], &V[2], -(obj->obj.rot.Z));
    }
  Cam[0] = pov->pos.X;
  Cam[1] = pov->pos.Y;
  Cam[2] = pov->pos.Z;
  tmp.a = powf(V[0], 2) + powf(V[1], 2) + powf(V[2], 2);
  tmp.b = 2 * (Cam[0] * V[0] + Cam[1] * V[1] + Cam[2] * V[2]);
  tmp.c = powf(Cam[0], 2) + powf(Cam[1], 2) + powf(Cam[2], 2)
    - powf(obj->obj.R, 2);
  tmp.delta = powf(tmp.b, 2) - 4 * tmp.a * tmp.c;
  tmp.k1 = (- tmp.b - sqrtf(tmp.delta)) / (2.0 * tmp.a);
  tmp.k2 = (- tmp.b + sqrtf(tmp.delta)) / (2.0 * tmp.a);
  obj->obj.calc = tmp;
}

void	calc_cylindre(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  t_calc tmp;
  float	V[3];
  float	Cam[3];

  V[0] = ray->Vx - obj->obj.pos.X;
  V[1] = ray->Vy + obj->obj.pos.Y;
  V[2] = ray->Vz - obj->obj.pos.Z;
  if (ray->bool)
    {
      rotate_x(&V[0], &V[1], &V[2], -(obj->obj.rot.X));
      rotate_y(&V[0], &V[1], &V[2], -(obj->obj.rot.Y));
      rotate_z(&V[0], &V[1], &V[2], -(obj->obj.rot.Z));
    }
  Cam[0] = pov->pos.X;
  Cam[1] = pov->pos.Y;
  Cam[2] = pov->pos.Z;
  tmp.a = powf(V[0], 2) + powf(V[1], 2);
  tmp.b = 2 * (Cam[0] * V[0] + Cam[1] * V[1]);
  tmp.c = powf(Cam[0], 2) + powf(Cam[1], 2) - powf(obj->obj.R, 2);
  tmp.delta = powf(tmp.b, 2) - 4 * tmp.a * tmp.c;
  tmp.k1 = (- tmp.b - sqrtf(tmp.delta)) / (2.0 * tmp.a);
  tmp.k2 = (- tmp.b + sqrtf(tmp.delta)) / (2.0 * tmp.a);
  obj->obj.calc = tmp;
}

void	calc_cone(t_mesh *pov, t_llist *obj, t_ray *ray)
{
  t_calc tmp;
  float	r;
  float	V[3];
  float	Cam[3];

  r = obj->obj.R;
  V[0] = ray->Vx - obj->obj.pos.X;
  V[1] = ray->Vy + obj->obj.pos.Y;
  V[2] = ray->Vz - obj->obj.pos.Z;
  if (ray->bool)
    {
      rotate_x(&V[0], &V[1], &V[2], -(obj->obj.rot.X));
      rotate_y(&V[0], &V[1], &V[2], -(obj->obj.rot.Y));
      rotate_z(&V[0], &V[1], &V[2], -(obj->obj.rot.Z));
    }
  Cam[0] = pov->pos.X;
  Cam[1] = pov->pos.Y;
  Cam[2] = pov->pos.Z;
  tmp.a = powf(V[0], 2) + powf(V[1], 2);
  tmp.b = 2.0 * (Cam[0] * V[0] + Cam[1] * V[1]);
  tmp.c = powf(Cam[0], 2) + powf(Cam[1], 2) - powf(tanf(r), 2) * powf(V[2], 2);
  tmp.delta = powf(tmp.b, 2) - 4 * tmp.a * tmp.c;
  tmp.k1 = (- tmp.b - sqrtf(tmp.delta)) / (2.0 * tmp.a);
  tmp.k2 = (- tmp.b + sqrtf(tmp.delta)) / (2.0 * tmp.a);
  obj->obj.calc = tmp;
}
