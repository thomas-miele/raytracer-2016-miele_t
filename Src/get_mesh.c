/*
** get_mesh.c for rt in /home/miele_t//TP/igraph/RayTracer/RT
** 
** Made by thomas miele
** Login   <miele_t@epitech.net>
** 
** Started on  Mon May 14 15:37:42 2012 thomas miele
** Last update Sat Jun  2 15:00:41 2012 thomas miele
*/

#include <stdlib.h>
#include "raytracer_42.h"

void	get_p(t_mesh *eye, t_llist *mesh, t_ray *ray)
{
  mesh->obj.P.X = eye->pos.X + (ray->K * ray->Vx);
  mesh->obj.P.Y = eye->pos.Y + (ray->K * ray->Vy);
  mesh->obj.P.Z = eye->pos.Z + (ray->K * ray->Vz);
}

void	get_plan(t_mesh *eye, t_llist *mesh, t_ray *ray)
{
  get_p(eye, mesh, ray);
  mesh->obj.N.X = 0 - mesh->obj.pos.X;
  mesh->obj.N.Y = 0 + mesh->obj.pos.Y;
  mesh->obj.N.Z = D - mesh->obj.pos.Z;
  rotate_x(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Z);
  rotate_y(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Y);
  rotate_z(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Z);
  ray->color = mesh->obj.color;
}

void	get_sphere(t_mesh *eye, t_llist *mesh, t_ray *ray)
{
  get_p(eye, mesh, ray);
  mesh->obj.N.X = mesh->obj.P.X - mesh->obj.pos.X;
  mesh->obj.N.Y = mesh->obj.P.Y + mesh->obj.pos.Y;
  mesh->obj.N.Z = mesh->obj.P.Z - mesh->obj.pos.Z;
  rotate_x(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.X);
  rotate_y(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Y);
  rotate_z(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Z);
  ray->color = mesh->obj.color;
}

void	get_cylindre(t_mesh *eye, t_llist *mesh, t_ray *ray)
{
  get_p(eye, mesh, ray);
  mesh->obj.N.X = mesh->obj.P.X - mesh->obj.pos.X;
  mesh->obj.N.Y = mesh->obj.P.Y + mesh->obj.pos.Y;
  mesh->obj.N.Z = 0 - mesh->obj.pos.Z;
  rotate_x(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.X);
  rotate_y(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Y);
  rotate_z(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Z);
  ray->color = mesh->obj.color;
}

void	get_cone(t_mesh *eye, t_llist *mesh, t_ray *ray)
{
  get_p(eye, mesh, ray);
  mesh->obj.N.X = mesh->obj.P.X - mesh->obj.pos.X;
  mesh->obj.N.Y = mesh->obj.P.Y + mesh->obj.pos.Y;
  mesh->obj.N.Z = (- mesh->obj.R * mesh->obj.P.Y) - mesh->obj.pos.Z;
  rotate_x(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.X);
  rotate_y(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Y);
  rotate_z(&mesh->obj.N.X, &mesh->obj.N.Y, &mesh->obj.N.Z, -mesh->obj.rot.Z);
  ray->color = mesh->obj.color;
}
