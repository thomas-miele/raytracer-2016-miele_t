/*
** raytracer.h for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src/Include
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 14:03:23 2012 thomas miele
** Last update Sat Jun  2 14:56:22 2012 thomas miele
*/

#ifndef		RAYTRACER_H__
#define		RAYTRACER_H__

unsigned int	calc(t_mesh *, t_llist *, t_llist *, t_ray *);
unsigned int	init_calc(t_mesh *, t_llist *, t_llist *, int, int);
int		raytracer(t_mlx *, t_mesh *, t_llist *, t_llist *);

void		init_camera(t_mesh *, float, float, float, float, float, float);
int		llist_len(t_llist *);
void		free_list(t_llist **);

int		add_spot(t_llist **, int, float, float, float, unsigned int);
int		add_mesh(t_llist **, int, float, float, float, float,
			 unsigned int, float, float, float, float);

#endif		/* !RAYTRACER_H__*/
