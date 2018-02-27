/*
** util_graph.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/test
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Wed Jan  4 21:10:17 2017 Lucas Benkemoun
** Last update Tue Jan 10 23:51:25 2017 Lucas Benkemoun
*/

#include "line.h"

sfColor         set_color(sfUint8 r, sfUint8 g, sfUint8 b)
{
  sfColor       color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  return (color);
}

sfVector2i      set_vector(int x, int y)
{
  sfVector2i    vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}

sfVector2f      set_vectorf(float x, float y)
{
  sfVector2f    vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}

sfColor         divid_color(sfColor color)
{
  color.r /= 1.6;
  color.g /= 1.6;
  color.b /= 1.6;
  return (color);
}
