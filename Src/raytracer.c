/*
** raytracer.c for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 14:26:10 2012 thomas miele
** Last update Sun Jun  3 17:11:07 2012 thomas miele
*/

#include <stdlib.h>
#include <float.h>
#include <stdio.h>
#include "raytracer_42.h"

t_Uint		calc(t_mesh *eye, t_llist *llist, t_llist *spot, t_ray *ray)
{
  t_llist	*tmp;
  float		k;
  int		ret;
  t_Uint	color;

  tmp = llist;
  k = FLT_MAX;
  color = 0x000000;
  while (tmp != NULL)
    {
      ret = inter_choice(eye, tmp, ray);
      if (ret == 1)
        {
          if (ray->K <= k)
            {
              k = ray->K;
	      color = luminosite(eye, tmp, spot, ray);
            }
        }
      tmp = tmp->nxt;
    }
  return (color);
}

t_Uint		init_calc(t_mesh *eye, t_llist *llist, t_llist *spot,
			  int x, int y)
{
  t_ray		ray;
  float		x1;
  float		y1;
  float		z1;
  t_Uint	color;

  x1 = D;
  y1 = (WIN_X / 2) - x;
  z1 = (WIN_Y / 2) - y;
  ray.Vx = x1 - eye->pos.X;
  ray.Vy = y1 - eye->pos.Y;
  ray.Vz = z1 - eye->pos.Z;
  ray.top_mesh = llist;
  ray.top_spot = spot;
  ray.bool = 1;
  rotate_x(&ray.Vx, &ray.Vy, &ray.Vz, -eye->rot.X);
  rotate_y(&ray.Vx, &ray.Vy, &ray.Vz, -eye->rot.Y);
  rotate_z(&ray.Vx, &ray.Vy, &ray.Vz, -eye->rot.Z);
  color = calc(eye, llist, spot, &ray);
  return (color);
}

int	raytracer(t_mlx *mlx, t_mesh *eye, t_llist *llist, t_llist *spot)
{
  int	x;
  int	y;
  t_Uint color;

  x = 0;
  y = 0;
  printf("##1 raytracer begin\n");
  while (y <= WIN_Y)
    {
      while (x <= WIN_X)
        {
          color = init_calc(eye, llist, spot, x, y);
          my_pixel_put_to_image(mlx, color, x, y);
          x++;
        }
      y++;
      x = 0;
    }
  return (0);
}
