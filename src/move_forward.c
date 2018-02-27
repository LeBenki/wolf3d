/*
** move_forward.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/src
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Fri Dec 23 20:38:21 2016 Lucas Benkemoun
** Last update Thu Dec 29 01:26:37 2016 Lucas Benkemoun
*/

#include "../line.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  pos.x += distance * cos(direction / (180 / M_PI));
  pos.y += distance * sin(direction / (180 / M_PI));
  return (pos);
}
