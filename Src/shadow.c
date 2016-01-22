/*
** shadow.c for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 10:02:17 2012 thomas miele
** Last update Sat Jun  2 16:27:46 2012 thomas miele
*/

#include <stdlib.h>
#include "raytracer_42.h"

/*
** luminosite : pov : camera & ray : vector view
** loop in each mesh of scene except current mesh,
** and calcul lighting.
** Test if pov is sunny or in shadow.
*/

t_rgb		shadow_color()
{
  t_rgb		color;

  color.r = 0x00;
  color.g = 0x00;
  color.b = 0x00;
  color.rgb = 0x000000;
  return (color);
}

t_rgb		shadow(t_mesh *pov, t_llist *mesh, t_llist *spot, t_ray *l)
{
  t_llist	*tmp = NULL;
  int		ret;
  t_rgb		color;
  int		nb_mesh;

  tmp = l->top_mesh;
  nb_mesh = llist_len(l->top_mesh);
  while (tmp != NULL)
    {
      if (tmp != mesh && nb_mesh > 1)
	{
	  ret = inter_choice(pov, tmp, l);
	  if (l->K > 0.0001 && l->K < 1.0)
	    {
	      init_color(&color);
	      return (color);
	    }
	}
      else
	color = light_color(pov, mesh, spot, l);
      tmp = tmp->nxt;
    }
  return (color);
}
