/*
** draw_wall.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/bonus
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Tue Jan 10 23:53:17 2017 Lucas Benkemoun
** Last update Sat Jan 14 21:18:00 2017 Lucas Benkemoun
*/

#include "line.h"

void            draw_sprite(t_my_framebuffer *framebuffer,
			    t_wall wall, sfImage **image, sfVector2f pos)
{
  double        wallX;
  int           texX;
  int           texY;
  sfColor       color;
  int           y;

  (wall.side == 0) ? wallX = pos.y + wall.distance * wall.rayDirY : 0;
  (wall.side) ? wallX = pos.x + wall.distance * wall.rayDirX : 0;
  1 ? wallX -= floor((wallX)), texX = (int)(wallX * (double)(TW)) : 0;
  y = (int)wall.save.x - 1;
  while (++y < (int)wall.save.y)
    {
      texY = (((y * 256 - HEIGHT * 128 + (int)wall.save.z * 128) * TH)
      	      / (int)wall.save.z) / 256;
      color = sfImage_getPixel(image[wall.hit - 1], texX, texY);
      (wall.side == 0) ? my_put_pixel(framebuffer, wall.x, y, color) :
	my_put_pixel(framebuffer, wall.x, y, divid_color(color));
    }
}

void            draw_line_wall(t_wall wall, t_my_framebuffer *framebuffer,
			       sfImage **image, sfVector2f pos)
{
  int           lineHeight;
  int           drawStart;
  int           drawEnd;
  sfVector3f    save;

  lineHeight = (int)(HEIGHT / wall.distance);
  drawStart = -lineHeight / 2 + HEIGHT / 2;
  if (drawStart < 0)
    drawStart = 0;
  drawEnd= lineHeight / 2 + HEIGHT / 2;
  if (drawEnd >= HEIGHT)
    drawEnd = HEIGHT - 1;
  save.x = drawStart;
  save.y = drawEnd;
  save.z = lineHeight;
  wall.save = save;
  draw_sprite(framebuffer, wall, image, pos);
}

void    draw_square(t_my_framebuffer *framebuffer,
		    int x, int y, sfColor color)
{
  int   y_save;

  y_save = y;
  while (x < WIDTH)
    {
      y = y_save;
      while (y < HEIGHT)
	{
	  my_put_pixel(framebuffer, x, y, color);
	  y = y + 1;
	}
      x = x + 1;
    }
}
