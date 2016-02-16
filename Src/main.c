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
#include <stdio.h>
#include "raytracer_42.h"

int		main(int ac, char **av)
{
  t_mlx		mlx;
  t_mesh	eye;
  t_llist	*llist = NULL;
  t_llist	*spot = NULL;

  printf("#1 init_mlx\n");
  init_mlx(&mlx);

  init_camera(&eye, -300, 0, 50, 0, 0, 0);
  add_spot(&spot, SPOT, -100, 200, 100, 0xffffff);

  // x : -near, +far
  // y : -left, +right
  // z : -bottom, +up
  add_mesh(&llist, PLAN, 0, 0, 0, 0, 0x6363ff, 0, 0, 0, 0);
  add_mesh(&llist, SPHERE, 150, -300, 0, 50, 0x00ff00, 0, 0, 0, 0);
  add_mesh(&llist, CYLINDRE, 0, 0, 0, 75, 0xff0000, 0.1, 0, 0, 0);
  add_mesh(&llist, CONE, 0, 250, 0, 50, 0xff00ff, 0.1, 0, 0, 0);

  printf("#2 raytracer\n");
  raytracer(&mlx, &eye, llist, spot);

  SDL_Event event;
  int loop = 1;

  printf("#3 sdl_loop\n");
  put_image_to_window(&mlx);
  while (loop != 0)
    {
      // events
      while (SDL_PollEvent(&event))
	{
	  switch (event.type)
	    {
	    case SDL_QUIT:
	      loop = 0;
	      break;
	    case SDL_KEYDOWN:
	      if (event.key.keysym.sym == SDLK_ESCAPE ||
		  event.key.keysym.sym == SDLK_s)
		loop = 0;
	      break;
	    default:
	      break;
	    }
	}
    }
  printf("#5 end loop\n");

  printf("#7 free raytracer\n");
  free_llist(&llist);
  free_llist(&spot);

  printf("#6 close SDL\n");
  SDL_DestroyRenderer(mlx.render);
  SDL_DestroyWindow(mlx.win);
  SDL_Quit();
  return (0);
}
