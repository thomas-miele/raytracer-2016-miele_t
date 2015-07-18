/*
** my_mlx.h for raytracer in /home/miele_t//TP/igraph/RayTracer/RT/Src/Include
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Sat Jun  2 13:29:30 2012 thomas miele
** Last update Sat Jun  2 14:52:59 2012 thomas miele
*/

#ifndef		MY_MLX_H__
#define		MY_MLX_H__

#include <SDL2/SDL.h>

#define		WIN_NAME	"raytracer"
#define		WIN_X		1080
#define		WIN_Y		720
#define		ESC		65307
#define		D		100

#define		RAD(deg)	((M_PI * (deg)) / 180)
#define		DEG(rad)	((180 * (rad)) / M_PI)

typedef struct	s_mlx
{
  SDL_Window	*win;
  SDL_Surface	*img;

  char		*data;
  int		bpp;
  int		size_line;
  int		endian;
}	t_mlx;

void		my_pixel_put_to_image(t_mlx *, unsigned int, int, int);
int		expose_event(void *);
int		key_event(int);
int		init_mlx(t_mlx *);

int		put_image_to_window(t_mlx *);

#endif		/* !MY_MLX_H__*/
