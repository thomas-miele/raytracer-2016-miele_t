/*
** main.c for RT in /home/miele_t//TP/RayTracer
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Wed Feb  1 15:09:39 2012 thomas miele
** Last update Thu Jun 14 14:36:54 2012 thomas miele
*/

#include <stdlib.h>
#include <mlx.h>
#include "Include/my_mlx.h"
#include "Include/struct.h"
#include "Include/raytracer.h"
#include "Include/color.h"
#include "Include/luminosite.h"

int		main(int ac, char **av)
{
  t_mlx		mlx;
  t_mesh	eye;
  t_llist	*llist = NULL;
  t_llist	*spot = NULL;

  init_mlx(&mlx);
  init_camera(&eye, -300, 0, 50, 0, 0, 0);
  add_spot(&spot, SPOT, -100, 200, 100, 0xffffff);

  add_mesh(&llist, PLAN, 0, 0, 0, 0, 0xff0000, 0.1, 0, 0, 0);
  add_mesh(&llist, CYLINDRE, 0, 0, 0, 100, 0xff0000, 0.9, 0, 0, 0);
  raytracer(&mlx, &eye, llist, spot);

  mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
  mlx_expose_hook(mlx.win_ptr, &expose_event, &mlx);
  mlx_key_hook(mlx.win_ptr, &key_event, 0);
  mlx_loop(mlx.mlx_ptr);
  free_llist(&llist);
  free_llist(&spot);
  return (0);
}
