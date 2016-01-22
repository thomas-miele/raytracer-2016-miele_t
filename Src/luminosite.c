/*
** luminosite.c for rt in /home/miele_t//RT/Src
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Fri Jun  1 10:12:11 2012 thomas miele
** Last update Sat Jun  2 16:14:57 2012 thomas miele
*/

#include <stdlib.h>
#include "raytracer_42.h"

/*
** pov : P(x, y, z) : Point of mesh.
** ray : L(Spot - P) : director vector.
*/

void		init_ray(t_mesh *pov, t_llist *mesh, t_llist *spot, t_ray *l)
{
  pov->pos.X = mesh->obj.P.X;
  pov->pos.Y = mesh->obj.P.Y;
  pov->pos.Z = mesh->obj.P.Z;
  pov->R = mesh->obj.R;
  pov->color = mesh->obj.color;
  pov->rot = mesh->obj.rot;
  pov->P = mesh->obj.P;
  pov->N = mesh->obj.N;

  l->bool = 0;
  l->Vx = spot->obj.pos.X - mesh->obj.pos.X;
  l->Vy = spot->obj.pos.Y - mesh->obj.pos.Y;
  l->Vz = spot->obj.pos.Z - mesh->obj.pos.Z;
  l->color = mesh->obj.color;
}

/*
** For one mesh, loop -> for each spot
** check shadow and light effect.
*/

t_Uint		luminosite(t_mesh *eye, t_llist *obj, t_llist *spot, t_ray *view)
{
  t_llist	*tmp = NULL;
  t_rgb		color;
  t_mesh	pov;
  t_ray		l;

  tmp = spot;
  color = obj->obj.color;
  l.top_mesh = view->top_mesh;
  l.top_spot = view->top_spot;
  while (tmp != NULL)
    {
      init_ray(&pov, obj, tmp, &l);
      color = shadow(&pov, obj, tmp, &l);
      tmp = tmp->nxt;
    }
  return (color.rgb);
}
