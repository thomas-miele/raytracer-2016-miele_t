/*
** mesh.h for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src/Include
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 13:48:36 2012 thomas miele
** Last update Sat Jun  2 14:50:46 2012 thomas miele
*/

#ifndef		MESH_H__
#define		MESH_H__

int		inter_choice(t_mesh *, t_llist *, t_ray *);
int		inter_sphere(t_mesh *, t_llist *, t_ray *);
int		inter_cylindre(t_mesh *, t_llist *, t_ray *);
int		inter_cone(t_mesh *, t_llist *, t_ray *);
int		inter_plan(t_mesh *, t_llist *, t_ray *);

int		calc_k(t_llist *, float *);
void		calc_sphere(t_mesh *, t_llist *, t_ray *);
void		calc_cylindre(t_mesh *, t_llist *, t_ray *);
void		calc_cone(t_mesh *, t_llist *, t_ray *);

void		get_p(t_mesh *, t_llist *, t_ray *);
void		get_plan(t_mesh *, t_llist *, t_ray *);
void		get_sphere(t_mesh *, t_llist *, t_ray *);
void		get_cylindre(t_mesh *, t_llist *, t_ray *);
void		get_cone(t_mesh *, t_llist *, t_ray *);

int		rotate_x(float *, float *, float *, float);
int		rotate_y(float *, float *, float *, float);
int		rotate_z(float *, float *, float *, float);

#endif		/* !MESH_H__*/
