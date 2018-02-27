/*
** my_draw.c for wireframe in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wireframe/other
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Fri Dec  9 16:43:55 2016 Lucas Benkemoun
** Last update Sat Dec 10 19:45:52 2016 Lucas Benkemoun
*/

#include "../line.h"

void                    my_draw_ver(t_my_framebuffer *framebuffer,
				    sfVector2i from, sfVector2i to, sfColor color)
{
  int                   dx;
  int                   dy;
  int                   i;
  int                   xinc;
  int                   yinc;
  int                   cumul;
  int                   x;
  int                   y;

  1 ? x = from.x, y = from.y : 0;
  1 ? dx = to.x - from.x, dy = to.y - from.y : 0;
  1 ? xinc = (dx > 0) ? 1 : -1, yinc = (dy > 0) ? 1 : -1 : 0;
  1 ? dx = abs(dx), dy = abs(dy) : 0;
  my_put_pixel(framebuffer, x, y, color);
  1 ? cumul = dy / 2, i = 0 : 0;
  while (++i <= dy)
    {
      y += yinc;
      cumul += dx;
      (cumul >= dy) ? cumul -= dy, x += xinc : 0;
      my_put_pixel(framebuffer, x, y, color);
    }
}
void                    my_draw_hor(t_my_framebuffer *framebuffer,
				    sfVector2i from, sfVector2i to, sfColor color)
{
  int                   dx;
  int                   dy;
  int                   i;
  int                   xinc;
  int                   yinc;
  int                   cumul;
  int                   x;
  int                   y;

  1 ? x = from.x, y = from.y : 0;
  1 ? dx = to.x - from.x, dy = to.y - from.y : 0;
  1 ? xinc = (dx > 0) ? 1 : -1, yinc = (dy > 0) ? 1 : -1 : 0;
  1 ? dx = abs(dx), dy = abs(dy) : 0;
  my_put_pixel(framebuffer, x, y, color);
  1 ? cumul = dx / 2, i = 0 : 0;
  while (++i <= dx)
    {
      x += xinc;
      cumul += dy;
      (cumul >= dx) ? cumul -= dx, y += yinc : 0;
      my_put_pixel(framebuffer, x, y, color);
    }
}

void                    my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to, sfColor color)
{
  int                   dx;
  int                   dy;
  int                   x;
  int                   y;

  1 ? x = from.x, y = from.y : 0;
  1 ? dx = to.x - from.x, dy = to.y - from.y : 0;
  1 ? dx = abs(dx), dy = abs(dy) : 0;
  my_put_pixel(framebuffer, x, y, color);
  if (dx > dy)
    my_draw_hor(framebuffer, from, to, color);
  else
    my_draw_ver(framebuffer, from, to, color);
}
