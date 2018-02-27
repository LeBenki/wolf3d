/*
** radar.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/bonus
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Thu Jan  5 22:52:26 2017 Lucas Benkemoun
** Last update Fri Jan 13 15:21:50 2017 Lucas Benkemoun
*/

#include "line.h"

void    my_square(t_my_framebuffer *framebuffer, sfVector2i p1,
		  sfColor color)
{
  int   y_save;
  int	x_max;
  int	y_max;

  y_save = p1.y;
  x_max = p1.x + 20;
  y_max = p1.y + 20;
  while (p1.x < x_max)
    {
      p1.y = y_save;
      while (p1.y < y_max)
	{
	  my_put_pixel(framebuffer, p1.x, p1.y, color);
	  p1.y = p1.y + 1;
	}
      p1.x = p1.x + 1;
    }
}

void		radar(sfVector2f pos, t_play *p)
{
  int		i;
  int		j;
  int		size;
  sfSprite	*sprite;
  sfTexture	*texture;

  size = 20;
  i = 0;
  j = 0;
  while (p->map[i])
    {
      j = 0;
      while (p->map[i][j])
  	  {
  	    if (p->map[i][j] - '0')
	      my_square(p->framebuffer, set_vector(size * i, size * j), sfBlack);
	    else if (j == (int)pos.y && i == (int)pos.x)
	      my_square(p->framebuffer, set_vector(size * i, size * j), sfRed);
	    else
	      my_square(p->framebuffer, set_vector(size * i, size * j), sfWhite);
  	    j++;
  	  }
      i++;
    }
}
