/*
** light.c for rt in /home/miele_t//TP/igraph/RayTracer/RT
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Mon May 14 15:43:54 2012 thomas miele
** Last update Sat Jun  2 16:33:15 2012 thomas miele
*/

#include <stdlib.h>
#include <math.h>
#include "Include/my_mlx.h"
#include "Include/struct.h"
#include "Include/raytracer.h"
#include "Include/color.h"
#include "Include/luminosite.h"
#include "Include/mesh.h"

float		get_cos(t_llist *obj, t_ray *l)
{
  float		cos;
  float		scalar;
  float		n_l;
  float		n_n;

  scalar = l->Vx * obj->obj.N.X + l->Vy * obj->obj.N.Y + l->Vz * obj->obj.N.Z;
  n_l = sqrtf(pow(l->Vx, 2) + pow(l->Vy, 2) + pow(l->Vz, 2));
  n_n = sqrtf(pow(obj->obj.N.X, 2) + pow(obj->obj.N.Y, 2)
	      + pow(obj->obj.N.Z, 2));
  cos = scalar / (n_l * n_n);
  if (cos < 0)
    cos = 0;
  return (cos);
}

t_rgb		light_color(t_mesh *pov, t_llist *mesh, t_llist *spot, t_ray *l)
{
  float		cos;
  t_rgb		color;
  float		bright;

  bright = mesh->obj.color.bright;
  color = mesh->obj.color;

  cos = get_cos(mesh, l);
  color.r = color.r * (1 - bright) + spot->obj.color.r * bright;
  color.g = color.g * (1 - bright) + spot->obj.color.g * bright;
  color.b = color.b * (1 - bright) + spot->obj.color.b * bright;
  color.r = color.r * cos;
  color.g = color.g * cos;
  color.b = color.b * cos;
  color.rgb = compose(&color);
  return (color);
}
