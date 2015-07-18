/*
** mesh.c for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 13:34:12 2012 thomas miele
** Last update Sun Jun  3 17:04:29 2012 thomas miele
*/

#include <stdlib.h>
#include "Include/my_mlx.h"
#include "Include/struct.h"
#include "Include/raytracer.h"
#include "Include/color.h"
#include "Include/luminosite.h"

int             add_mesh(t_llist **llist, int type, float x, float y, float z,
			 float r, t_Uint color, float bright,
			 float xrot, float yrot, float zrot)
{
  t_llist       *new = NULL;
  t_rgb         tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (0);
  tmp = decompose(color);
  new->type = type;
  new->obj.pos.X = x;
  new->obj.pos.Y = y;
  new->obj.pos.Z = z;
  new->obj.R = r;
  new->obj.color = tmp;
  new->obj.color.bright = bright;
  new->obj.rot.X = xrot;
  new->obj.rot.Y = yrot;
  new->obj.rot.Z = zrot;
  new->nxt = *llist;
  *llist = new;
  return (0);
}

int		add_spot(t_llist **spot, int type,
			 float x, float y, float z, t_Uint color)
{
  t_llist	*new = NULL;
  t_rgb		tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (0);
  tmp = decompose(color);
  new->type = type;
  new->obj.pos.X = x;
  new->obj.pos.Y = y;
  new->obj.pos.Z = z;
  new->obj.color = tmp;
  new->nxt = *spot;
  *spot = new;
  return (0);
}

void		free_llist(t_llist **llist)
{
  t_llist	*tmp = NULL;
  t_llist	*tmp_nxt = NULL;

  tmp = *llist;
  while (tmp != NULL)
    {
      tmp_nxt = tmp->nxt;
      free(tmp);
      tmp = tmp_nxt;
    }
}
