/*
** color.h for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src/Include
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 13:56:15 2012 thomas miele
** Last update Sat Jun  2 15:10:26 2012 thomas miele
*/

#ifndef		COLOR_H__
#define		COLOR_H__

unsigned int	compose(t_rgb *);
t_rgb           decompose(unsigned int);
void            update_color(t_rgb *, t_rgb *);
void            init_color(t_rgb *);

#endif		/* !COLOR_H__*/
