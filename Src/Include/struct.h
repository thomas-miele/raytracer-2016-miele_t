/*
** struct.h for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src/Include
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 14:07:19 2012 thomas miele
** Last update Sat Jun  2 16:14:04 2012 thomas miele
*/

#ifndef		STRUCT_H__
#define		STRUCT_H__

#define		SPOT		(-1)
#define		CAMERA		0
#define		PLAN		1
#define		SPHERE		2
#define		CYLINDRE	3
#define		CONE		4

typedef		unsigned int	t_Uint;

typedef struct	s_vector
{
  float		X;
  float		Y;
  float		Z;
}	t_vct;

typedef struct	s_rgb
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
  unsigned int	rgb;
  float		bright;
}	t_rgb;

typedef struct	s_calc
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k1;
  float		k2;
}	t_calc;

typedef struct	s_mesh
{
  t_vct		pos;
  t_vct		rot;
  t_rgb		color;
  float		R;
  t_calc	calc;
  t_vct		P;
  t_vct		N;
}	t_mesh;

typedef struct	s_ray
{
  int		bool;
  float		Vx;
  float		Vy;
  float		Vz;
  float		K;
  t_rgb		color;
  struct s_llist *top_mesh;
  struct s_llist *top_spot;
}	t_ray;

typedef struct	s_llist
{
  int		type;
  struct s_llist *nxt;
  t_mesh	obj;
}	t_llist;

#endif		/* !STRUCT_H__*/
