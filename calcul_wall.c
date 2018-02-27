/*
** calcul_wall.c for wolf3d in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wolf3d/test
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Tue Jan  3 14:43:20 2017 Lucas Benkemoun
** Last update Tue Jan 10 20:37:39 2017 Lucas Benkemoun
*/

#include "line.h"

t_wall          calcul_dist(sfVector2f *p,
			    sfVector2f *dir, sfVector2f plane, char **map)
{
  t_ray		r;
  t_wall        w;

  1 ? r.mapX = (int)p->x, r.mapY = (int)p->y, w.hit = 0,
    w.rayDirX = dir->x + plane.x, w.rayDirY = dir->y + plane.y : 0;
  r.deltaDistX = sqrt(1 + (w.rayDirY * w.rayDirY) / (w.rayDirX * w.rayDirX));
  r.deltaDistY = sqrt(1 + (w.rayDirX * w.rayDirX) / (w.rayDirY * w.rayDirY));
  (w.rayDirX < 0) ? r.stepX = -1,
    r.sideDistX = (p->x - r.mapX) * r.deltaDistX : 0;
  (w.rayDirX >= 0) ? r.stepX = 1,
    r.sideDistX = (r.mapX + 1.0 - p->x) * r.deltaDistX : 0;
  (w.rayDirY < 0) ? r.stepY = -1,
    r.sideDistY = (p->y - r.mapY) * r.deltaDistY : 0;
  (w.rayDirY >= 0) ? r.stepY = 1,
    r.sideDistY = (r.mapY + 1.0 - p->y) * r.deltaDistY : 0;
  while (!w.hit)
    {
      (r.sideDistX < r.sideDistY) ? 1 ? r.sideDistX += r.deltaDistX,
	r.mapX += r.stepX, w.side = 0 : 0 : 1 ?
	r.sideDistY += r.deltaDistY, r.mapY += r.stepY, w.side = 1 : 0;
      (map[r.mapX][r.mapY] - '0') ? w.hit = map[r.mapX][r.mapY] - '0' : 0;
    }
  (!w.side) ? w.distance = (r.mapX - p->x + (1 - r.stepX) / 2) / w.rayDirX : 0;
  (w.side) ? w.distance = (r.mapY - p->y + (1 - r.stepY) / 2) / w.rayDirY : 0;
  return (w);
}
