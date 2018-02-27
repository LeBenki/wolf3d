/*
** keyboard.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/test
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Wed Jan  4 21:02:56 2017 Lucas Benkemoun
** Last update Sun Jan 15 22:03:08 2017 Lucas Benkemoun
*/

#include "line.h"

void		turn_around(sfVector2f *dir, sfVector2f *plane, int x, int y)
{
  float		rotSpeed;
  float		temp;
  sfEvent	*event;

  rotSpeed = 0.04;
  if (sfKeyboard_isKeyPressed(sfKeyRight) || x > 40)
    {
      temp = dir->x;
      dir->x = dir->x * cos(-rotSpeed) - dir->y * sin(-rotSpeed);
      dir->y = temp * sin(-rotSpeed) + dir->y * cos(-rotSpeed);
      temp = plane->x;
      plane->x = plane->x * cos(-rotSpeed) - plane->y * sin(-rotSpeed);
      plane->y = temp * sin(-rotSpeed) + plane->y * cos(-rotSpeed);
    }
  if (sfKeyboard_isKeyPressed(sfKeyLeft) || x < -40)
    {
      temp = dir->x;
      dir->x = dir->x * cos(rotSpeed) - dir->y * sin(rotSpeed);
      dir->y = temp * sin(rotSpeed) + dir->y * cos(rotSpeed);
      temp = plane->x;
      plane->x = plane->x * cos(rotSpeed) - plane->y * sin(rotSpeed);
      plane->y = temp * sin(rotSpeed) + plane->y * cos(rotSpeed);
    }
}

void    keyboard_ctrl(sfVector2f *pos,
		      sfVector2f *dir, char **map)
{
  float	moveSpeed;
  int	y;

  y = (int)(sfJoystick_getAxisPosition(0, sfJoystickY));
  moveSpeed = 0.01;
  if ((sfKeyboard_isKeyPressed(sfKeyZ) || y < -40) &&
      (sfKeyboard_isKeyPressed(sfKeyLControl) ||
       sfJoystick_isButtonPressed(0, 2)) &&
      (map[(int)(pos->x + dir->x * (moveSpeed * 0.5))][(int)(pos->y)] == 48) &&
      (map[(int)(pos->x)][(int)(pos->y + dir->y * (moveSpeed * 0.5))] == 48))
    1 ? pos->x += dir->x * (moveSpeed * 0.5),
      pos->y += dir->y * (moveSpeed * 0.5): 0;
  if ((sfKeyboard_isKeyPressed(sfKeyS) || y > 40) &&
      (sfKeyboard_isKeyPressed(sfKeyLControl) ||
       sfJoystick_isButtonPressed(0, 2)) &&
      (map[(int)(pos->x - dir->x * (moveSpeed * 0.5))][(int)(pos->y)] == 48) &&
      (map[(int)(pos->x)][(int)(pos->y - dir->y * (moveSpeed * 0.5))] == 48))
    1 ? pos->x -= dir->x * (moveSpeed * 0.5),
      pos->y -= dir->y * (moveSpeed * 0.5): 0;
}

void		action(sfVector2f *pos,
		       sfVector2f *dir, int hud, char **map)
{
  float		moveSpeed;
  int		x;
  int		y;

  x = (int)(sfJoystick_getAxisPosition(0, sfJoystickX));
  y = (int)(sfJoystick_getAxisPosition(0, sfJoystickY));
  moveSpeed = 0.1;
  if ((sfKeyboard_isKeyPressed(sfKeyZ) || y < -40) &&
  (sfKeyboard_isKeyPressed(sfKeyLShift) || sfJoystick_isButtonPressed(0, 0)) &&
  (map[(int)(pos->x + dir->x * moveSpeed * 1.1)][(int)(pos->y)] == 48) &&
  (map[(int)(pos->x)][(int)(pos->y + dir->y * moveSpeed * 1.1)] == 48))
    1 ? pos->x += dir->x * moveSpeed * 1.1,
      pos->y += dir->y * moveSpeed * 1.1: 0;
  casser(pos, dir, hud, map);
  placer(pos, dir, hud, map);
}

void		moove(sfVector2f *pos,
		      sfVector2f *dir, sfVector2f *plane, char **map)
{
  float		moveSpeed;
  int		x;
  int		y;

  moveSpeed = 0.1;
  x = (int)(sfJoystick_getAxisPosition(0, sfJoystickX));
  y = (int)(sfJoystick_getAxisPosition(0, sfJoystickY));
  if ((sfKeyboard_isKeyPressed(sfKeyQ) || sfJoystick_isButtonPressed(0, 6)) &&
      !sfKeyboard_isKeyPressed(sfKeyLControl) &&
      (map[(int)(pos->x - plane->x * moveSpeed)][(int)(pos->y)] == 48) &&
      (map[(int)(pos->x)][(int)(pos->y - plane->y * moveSpeed)] == 48))
    1 ? pos->x -= plane->x * moveSpeed, pos->y -= plane->y * moveSpeed : 0;
  if ((sfKeyboard_isKeyPressed(sfKeyD) || sfJoystick_isButtonPressed(0, 7)) &&
      !sfKeyboard_isKeyPressed(sfKeyLControl) &&
      (map[(int)(pos->x + plane->x * moveSpeed)][(int)(pos->y)] == 48) &&
      (map[(int)(pos->x)][(int)(pos->y + plane->y * moveSpeed)] == 48))
    1 ? pos->x += plane->x * moveSpeed, pos->y += plane->y * moveSpeed : 0;
}

void		keyboard(sfVector2f *pos,
			 sfVector2f *dir, sfVector2f *plane, char **map)
{
  float		moveSpeed;
  int		x;
  int		y;

  moveSpeed = 0.1;
  sfJoystick_update();
  x = (int)(sfJoystick_getAxisPosition(0, sfJoystickX));
  y = (int)(sfJoystick_getAxisPosition(0, sfJoystickY));
  if ((sfKeyboard_isKeyPressed(sfKeyZ) || (y < -40)) &&
      !sfKeyboard_isKeyPressed(sfKeyLControl) &&
      !sfJoystick_isButtonPressed(0, 2) &&
      (map[(int)(pos->x + dir->x * moveSpeed)][(int)(pos->y)] == 48) &&
      (map[(int)(pos->x)][(int)(pos->y + dir->y * moveSpeed)] == 48))
    1 ? pos->x += dir->x * moveSpeed, pos->y += dir->y * moveSpeed : 0;
  if ((sfKeyboard_isKeyPressed(sfKeyS) || (y > 40)) &&
      !sfKeyboard_isKeyPressed(sfKeyLControl) &&
      !sfJoystick_isButtonPressed(0, 2) &&
      (map[(int)(pos->x - dir->x * moveSpeed)][(int)(pos->y)] == 48) &&
      (map[(int)(pos->x)][(int)(pos->y - dir->y * moveSpeed)] == 48))
    1 ? pos->x -= dir->x * moveSpeed, pos->y -= dir->y * moveSpeed : 0;
  turn_around(dir, plane, x, y);
  keyboard_ctrl(pos, dir, map);
  moove(pos, dir, plane, map);
}
