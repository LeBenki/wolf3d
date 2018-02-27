/*
** window.c for wireframe in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wireframe/src
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Fri Dec  9 14:45:45 2016 Lucas Benkemoun
** Last update Sun Jan 15 17:53:13 2017 Lucas Benkemoun
*/

#include "../line.h"

sfRenderWindow*         create_window(char* name, int width, int height)
{
  sfRenderWindow*       window;
  sfVideoMode           mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name,
				 sfResize | sfClose | sfFullscreen, NULL);
  sfRenderWindow_setMouseCursorVisible(window, 0);
  if (window == NULL)
    exit(EXIT_FAILURE);
  return (window);
}

t_my_framebuffer                *my_framebuffer_create(int width,
						       int height)
{
  int                           i;
  t_my_framebuffer              *fb;

  i = 0;
  fb = malloc(sizeof(t_my_framebuffer));
  fb->width = width;
  fb->height = height;
  fb->pixels = malloc(width * height * 4 * sizeof(*(fb->pixels)));
  if ((fb->pixels) == NULL)
    exit(0);
  while (i < width * height * 4)
    {
      fb->pixels[i] = 0;
      i++;
    }
  return (fb);
}
