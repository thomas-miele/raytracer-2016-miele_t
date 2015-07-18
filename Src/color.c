/*
** lib_color.c for rt in /home/miele_t//TP/igraph/RayTracer/RT
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Thu May 24 11:04:15 2012 thomas miele
** Last update Sat Jun  2 15:00:31 2012 thomas miele
*/

#include <stdlib.h>
#include "Include/my_mlx.h"
#include "Include/struct.h"
#include "Include/raytracer.h"
#include "Include/color.h"
#include "Include/luminosite.h"

int		count_spot(t_llist *llist)
{
  int		nb;
  t_llist	*tmp;

  nb = 0;
  tmp = llist;
  while (tmp != NULL)
    {
      nb++;
      tmp = tmp->nxt;
    }
  return (nb);
}

void	update_color(t_rgb *src, t_rgb *target)
{
  target->r = src->r;
  target->g = src->g;
  target->b = src->b;
  target->rgb = src->rgb;
  target->bright = src->bright;
}

t_Uint		compose(t_rgb *color)
{
  t_Uint	res;
  t_Uint	r;
  t_Uint	g;
  t_Uint	b;

  r = color->r;
  g = color->g;
  b = color->b;
  res = r << 16 | g << 8 | b;
  return (res);
}

t_rgb	decompose(t_Uint color)
{
  t_rgb res;

  res.r = (color & 0xFF0000) >> 16;
  res.g = (color & 0xFF00) >> 8;
  res.b = (color & 0xFF);
  res.rgb = color;
  res.bright = 0;
  return (res);
}
