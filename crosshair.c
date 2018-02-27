/*
** crosshair.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/test
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Thu Jan  5 00:06:15 2017 Lucas Benkemoun
** Last update Thu Jan  5 00:06:31 2017 Lucas Benkemoun
*/

#include "line.h"

void    draw_crosshair(t_my_framebuffer *framebuffer, sfColor color)
{
  my_draw_line(framebuffer, set_vector(WIDTH / 2 + 5, HEIGHT / 2 - 1),
	       set_vector(WIDTH / 2 + 15, HEIGHT / 2 - 1), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 + 5, HEIGHT / 2),
	       set_vector(WIDTH / 2 + 15, HEIGHT / 2), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 + 5, HEIGHT / 2 + 1),
	       set_vector(WIDTH / 2 + 15, HEIGHT / 2 + 1), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 - 5, HEIGHT / 2 - 1),
	       set_vector(WIDTH / 2 - 15, HEIGHT / 2 - 1), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 - 5, HEIGHT / 2),
	       set_vector(WIDTH / 2 - 15, HEIGHT / 2), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 - 5, HEIGHT / 2 + 1),
	       set_vector(WIDTH / 2 - 15, HEIGHT / 2 + 1), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2, HEIGHT / 2 + 5),
	       set_vector(WIDTH / 2, HEIGHT / 2 + 15), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 - 1, HEIGHT / 2 + 5),
	       set_vector(WIDTH / 2 - 1, HEIGHT / 2 + 15), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 + 1, HEIGHT / 2 + 5),
	       set_vector(WIDTH / 2 + 1, HEIGHT / 2 + 15), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2, HEIGHT / 2 - 5),
	       set_vector(WIDTH / 2, HEIGHT / 2 - 15), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 - 1, HEIGHT / 2 - 5),
	       set_vector(WIDTH / 2 - 1, HEIGHT / 2 - 15), color);
  my_draw_line(framebuffer, set_vector(WIDTH / 2 + 1, HEIGHT / 2 - 5),
	       set_vector(WIDTH / 2 + 1, HEIGHT / 2 - 15), color);
}
