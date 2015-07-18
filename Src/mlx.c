/*
** mlx.c for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 13:26:44 2012 thomas miele
** Last update Sun Jun  3 17:10:28 2012 thomas miele
*/

#include "Include/my_mlx.h"

void    my_pixel_put_to_image(t_mlx *mlx, t_Uint color, int x, int y)
{
  int   pixel;
  char  r;
  char  g;
  char  b;

  r = (color & 0xFF0000) >> 16;
  g = (color & 0xFF00) >> 8;
  b = (color & 0xFF);
  pixel = (y * mlx->size_line) + x * (mlx->bpp / 8);
  mlx->data[pixel] = b;
  mlx->data[pixel + 1] = g;
  mlx->data[pixel + 2] = r;
}

int     expose_event(void *param)
{
  t_mlx *tmp;

  tmp = (t_mlx *)param;
  mlx_put_image_to_window(tmp->mlx_ptr, tmp->win_ptr, tmp->img_ptr,  0, 0);
  return (0);
}

int     key_event(int keycode)
{
  if (keycode == ESC)
    exit(0);
  return (0);
}

int     init_mlx(t_mlx *mlx)
{
  //  ret = mlx->mlx_ptr = mlx_init();
  if (SDL_Init(SDL_INIT_VIDEO))
    {
      exit(EXIT_FAILURE);
    }
  //  ret = mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, WIN_NAME);
  mlx->win = SDL_CreateWindow(WIN_NAME,
			      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			      WIN_X, WIN_Y,
			      SDL_WINDOW_SHOWN);
  if (mlx->win == NULL)
    {
      exit(EXIT_FAILURE);
    }
  mlx->img = SDL_GetWindowSurface(mlx->win);
  if (mlx->img == NULL)
    {
      exit(EXIT_FAILURE);
    }
  //  ret = mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y);
  /*
    mlx->data = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp),
				&(mlx->size_line), &(mlx->endian));
  */
}
