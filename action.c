/*
** action.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/bonus
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Sun Jan 15 00:30:13 2017 Lucas Benkemoun
** Last update Sun Jan 15 00:30:58 2017 Lucas Benkemoun
*/

#include "line.h"

void            placer(sfVector2f *pos,
		       sfVector2f *dir, int hud, char **map)
{
  int           x;
  int           y;

  x = (int)(sfJoystick_getAxisPosition(0, sfJoystickX));
  y = (int)(sfJoystick_getAxisPosition(0, sfJoystickY));
  if ((sfKeyboard_isKeyPressed(sfKeySpace) ||
       sfJoystick_isButtonPressed(0, 3)) &&
      (map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] == '0'))
    {
      if (hud == 6)
	map[(int)(pos->x + dir->x * 1.1)][(int)(pos->y + dir->y * 1.1)] = '1';
      if (hud == 7)
	map[(int)(pos->x + dir->x * 1.1)][(int)(pos->y + dir->y * 1.1)] = '5';
      if (hud == 8)
	map[(int)(pos->x + dir->x * 1.1)][(int)(pos->y + dir->y * 1.1)] = '7';
      if (hud == 9)
	map[(int)(pos->x + dir->x * 1.1)][(int)(pos->y + dir->y * 1.1)] = '4';
    }
}

void            casser(sfVector2f *pos,
		       sfVector2f *dir, int hud, char **map)
{
  if ((sfKeyboard_isKeyPressed(sfKeyP) || sfJoystick_isButtonPressed(0, 1)) &&
      (map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] != '2') &&
      hud == 3)
    map[(int)(pos->x + dir->x * 1)][(int)(pos->y + dir->y * 1)] = '0';
  if ((sfKeyboard_isKeyPressed(sfKeyP) || sfJoystick_isButtonPressed(0, 1)) &&
      (map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] == '3') &&
      hud == 2)
    map[(int)(pos->x + dir->x * 1)][(int)(pos->y + dir->y * 1)] = '0';
  if ((sfKeyboard_isKeyPressed(sfKeyP) || sfJoystick_isButtonPressed(0, 1)) &&
      ((map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] == '6') ||
       (map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] == '9')) &&
      hud == 4)
    map[(int)(pos->x + dir->x * 1)][(int)(pos->y + dir->y * 1)] = '0';
  if ((sfKeyboard_isKeyPressed(sfKeyP) || sfJoystick_isButtonPressed(0, 1)) &&
      ((map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] == '4') ||
       (map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] == '7') ||
       (map[(int)(pos->x + 1 * dir->x)][(int)(pos->y + 1 * dir->y)] == '8')) &&
      hud == 5)
    map[(int)(pos->x + dir->x * 1)][(int)(pos->y + dir->y * 1)] = '0';
}
