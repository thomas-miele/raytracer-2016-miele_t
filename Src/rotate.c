/*
** rotate.c for rt in /home/miele_t//TP/igraph/RayTracer/RT
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Mon May 21 13:04:11 2012 thomas miele
** Last update Sat Jun  2 15:03:02 2012 thomas miele
*/

#include <math.h>
#include "Include/my_mlx.h"
#include "Include/struct.h"
#include "Include/raytracer.h"
#include "Include/color.h"
#include "Include/luminosite.h"

int     rotate_x(float *x, float *y, float *z, float angle)
{
  float x1, y1, z1;
  float rot_x[3][3] = {0};

  rot_x[0][0] = 1;
  rot_x[1][1] = cosf(RAD(angle));
  rot_x[1][2] = - sinf(RAD(angle));
  rot_x[2][1] = sinf(RAD(angle));
  rot_x[2][2] = cosf(RAD(angle));

  x1 = *x * rot_x[0][0] + *y * rot_x[0][1] + *z * rot_x[0][2];
  y1 = *x * rot_x[1][0] + *y * rot_x[1][1] + *z * rot_x[1][2];
  z1 = *x * rot_x[2][0] + *y * rot_x[2][1] + *z * rot_x[2][2];

  *x = x1;
  *y = y1;
  *z = z1;
  return (0);
}

int     rotate_y(float *x, float *y, float *z, float angle)
{
  float x1, y1, z1;
  float rot_y[3][3] = {0};

  rot_y[0][0] = cosf(RAD(angle));
  rot_y[0][2] = sinf(RAD(angle));
  rot_y[1][1] = 1;
  rot_y[2][0] = - sinf(RAD(angle));
  rot_y[2][2] = cosf(RAD(angle));

  x1 = *x * rot_y[0][0] + *y * rot_y[0][1] + *z * rot_y[0][2];
  y1 = *x * rot_y[1][0] + *y * rot_y[1][1] + *z * rot_y[1][2];
  z1 = *x * rot_y[2][0] + *y * rot_y[2][1] + *z * rot_y[2][2];

  *x = x1;
  *y = y1;
  *z = z1;
  return (0);
}

int     rotate_z(float *x, float *y, float *z, float angle)
{
  float x1, y1, z1;
  float rot_z[3][3] = {0};

  rot_z[0][0] = cosf(RAD(angle));
  rot_z[0][1] = - sinf(RAD(angle));
  rot_z[1][0] = sinf(RAD(angle));
  rot_z[1][1] = cosf(RAD(angle));
  rot_z[2][2] = 1;

  x1 = *x * rot_z[0][0] + *y * rot_z[0][1] + *z * rot_z[0][2];
  y1 = *x * rot_z[1][0] + *y * rot_z[1][1] + *z * rot_z[1][2];
  z1 = *x * rot_z[2][0] + *y * rot_z[2][1] + *z * rot_z[2][2];

  *x = x1;
  *y = y1;
  *z = z1;
  return (0);
}
