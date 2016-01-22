/*
** llist.c for rtv1 in /home/miele_t//TP/igraph/RayTracer/llist
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Mon Mar  5 15:01:07 2012 thomas miele
** Last update Sun Jun  3 17:03:17 2012 thomas miele
*/

#include <stdlib.h>
#include "raytracer_42.h"

void	init_camera(t_mesh *eye, float x, float y, float z,
		    float xrot, float yrot, float zrot)
{
  eye->pos.X = x;
  eye->pos.Y = y;
  eye->pos.Z = z;
  eye->rot.X = xrot;
  eye->rot.Y = yrot;
  eye->rot.Z = zrot;
}

int		llist_len(t_llist *top)
{
  t_llist	*tmp = NULL;
  int		len = 0;

  tmp = top;
  while (tmp != NULL)
    {
      len++;
      tmp = tmp->nxt;
    }
  return (len);
}

void		init_color(t_rgb *rgb)
{
  rgb->r = 0x00;
  rgb->g = 0x00;
  rgb->b = 0x00;
  rgb->rgb = 0x000000;
}
