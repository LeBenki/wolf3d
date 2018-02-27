/*
** line.c for bswireframe in /home/lucas99.06/Epitech/Semester1/Graph_Prog/bswireframe
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Mon Nov 14 10:14:07 2016 Lucas Benkemoun
** Last update Sat Dec 10 14:47:05 2016 Lucas Benkemoun
*/

#include "../line.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x, int y, sfColor color)
{
  if ((x <= 0 || y <= 0) ||
      (x >= framebuffer->width || y >= framebuffer->height))
    return;
  framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = 255;
}
