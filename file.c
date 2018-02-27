/*
** file.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/bonus
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Tue Jan 10 23:51:46 2017 Lucas Benkemoun
** Last update Sun Jan 15 17:03:59 2017 Lucas Benkemoun
*/

#include "line.h"

sfImage         **load_files(sfImage **image)
{
  image = malloc(sizeof(*image) * 9);
  image[0] = sfImage_createFromFile("64x64/grass_side.png");
  image[1] = sfImage_createFromFile("64x64/bedrock.png");
  image[2] = sfImage_createFromFile("64x64/tnt_side.png");
  image[3] = sfImage_createFromFile("64x64/glowstone.png");
  image[4] = sfImage_createFromFile("bonaldi.png");
  image[5] = sfImage_createFromFile("64x64/log_spruce.png");
  image[6] = sfImage_createFromFile("64x64/cobblestone.png");
  image[7] = sfImage_createFromFile("64x64/brick.png");
  image[8] = sfImage_createFromFile("64x64/bookshelf.png");
  return (image);
}

sfTexture         **load_hud(sfTexture **texture)
{
  texture = malloc(sizeof(*texture) * 10);
  texture[0] = sfTexture_createFromFile("1st_case.png", NULL);
  texture[1] = sfTexture_createFromFile("2nd_case.png", NULL);
  texture[2] = sfTexture_createFromFile("3rd_case.png", NULL);
  texture[3] = sfTexture_createFromFile("4th_case.png", NULL);
  texture[4] = sfTexture_createFromFile("5th_case.png", NULL);
  texture[5] = sfTexture_createFromFile("6th_case.png", NULL);
  texture[6] = sfTexture_createFromFile("7th_case.png", NULL);
  texture[7] = sfTexture_createFromFile("8th_case.png", NULL);
  texture[8] = sfTexture_createFromFile("9th_case.png", NULL);
  texture[9] = sfTexture_createFromFile("menu/back.jpg", NULL);
  return (texture);
}

void                    refresh(t_play *p, sfSprite *sprite)
{
  sfTexture_updateFromPixels(p->texture,
  			     p->framebuffer->pixels, WIDTH, HEIGHT, 0, 0);
  sfRenderWindow_clear(p->window, sfBlack);
  sfRenderWindow_drawSprite(p->window, p->sprite, NULL);
  sfRenderWindow_drawSprite(p->window, sprite, NULL);
  sfRenderWindow_display(p->window);
  draw_square(p->framebuffer, 0, 0, set_color(116, 208, 241));
  draw_square(p->framebuffer, 0, HEIGHT / 2, set_color(58, 157, 35));
}

void			hud_inv(sfSprite *sprite,
				sfTexture **texture, t_play *p, int *hud)
{
  if (sfJoystick_isButtonPressed(0, 4) && *hud > 1)
    1 ? sfSprite_setTexture(sprite, texture[*hud - 2], sfTrue), *hud -= 1 : 0;
  if (sfJoystick_isButtonPressed(0, 5) && *hud < 9)
    1 ? sfSprite_setTexture(sprite, texture[*hud], sfTrue), *hud += 1 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyEscape) || sfJoystick_isButtonPressed(0, 8))
    sfRenderWindow_close(p->window);
  if (sfKeyboard_isKeyPressed(sfKeyF1))
    1 ? sfSprite_setTexture(sprite, texture[0], sfTrue), *hud = 1 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF2))
    1 ? sfSprite_setTexture(sprite, texture[1], sfTrue), *hud = 2 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF3))
    1 ? sfSprite_setTexture(sprite, texture[2], sfTrue), *hud = 3 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF4))
    1 ? sfSprite_setTexture(sprite, texture[3], sfTrue), *hud = 4 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF5))
    1 ? sfSprite_setTexture(sprite, texture[4], sfTrue), *hud = 5 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF6))
    1 ? sfSprite_setTexture(sprite, texture[5], sfTrue), *hud = 6 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF7))
    1 ? sfSprite_setTexture(sprite, texture[6], sfTrue), *hud = 7 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF8))
    1 ? sfSprite_setTexture(sprite, texture[7], sfTrue), *hud = 8 : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF9))
    1 ? sfSprite_setTexture(sprite, texture[8], sfTrue), *hud = 9 : 0;
}
