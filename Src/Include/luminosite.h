/*
** luminosite.h for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src/Include
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 14:01:17 2012 thomas miele
** Last update Sat Jun  2 14:49:40 2012 thomas miele
*/

#ifndef		LUMINOSITE_H__
#define		LUMINOSITE_H__

float		get_cos(t_llist *, t_ray *);
t_rgb		light_color(t_mesh *, t_llist *, t_llist *, t_ray *);
t_rgb		shadow_color();
t_rgb		shadow(t_mesh *, t_llist *, t_llist *, t_ray *);
void		init_ray(t_mesh *, t_llist *, t_llist *, t_ray *);
t_Uint		luminosite(t_mesh *, t_llist *, t_llist *, t_ray *);

#endif		/* !LUMINOSITE_H__*/
