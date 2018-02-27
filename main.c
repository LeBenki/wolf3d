/*
** main.c for main in /home/lucas99.06/Epitech/Semester1/Graph_Prog/bswireframe
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Mon Nov 14 17:50:15 2016 Lucas Benkemoun
** Last update Sun Jan 15 22:03:18 2017 Lucas Benkemoun
*/

#include "line.h"

t_game			init_game()
{
  t_game		game;

  1 ? game.pos.x = 2.2, game.pos.y = 2.2 : 0;
  1 ? game.dir.x = -1, game.dir.y = 0 : 0;
  1 ? game.plane.x = 0.1, game.plane.y = 0.6 : 0;
  game.hud = 3;
  game.texture = load_hud(game.texture);
  game.sprite = sfSprite_create();
  sfSprite_setTexture(game.sprite, game.texture[9], sfTrue);
  game.image = load_files(game.image);
  return (game);
}

void			loop_menu(t_play *p, t_game *game, int *menu)
{
  while (*menu == 1)
    {
      sfJoystick_update();
      refresh(p, game->sprite);
      if (sfKeyboard_isKeyPressed(sfKeySpace) ||
	  sfJoystick_isButtonPressed(0, 7))
	1 ? sfSprite_setTexture(game->sprite,
				game->texture[2], sfTrue), *menu = 0 : 0;
      if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
	  sfJoystick_isButtonPressed(0, 8))
	{
	  sfRenderWindow_close(p->window);
	  exit(0);
	}
    }
}
void			play(t_play *p)
{
  t_wall                wall;
  t_game		game;
  int			menu;

  game = init_game();
  menu = 1;
  while (sfRenderWindow_isOpen(p->window))
    {
      loop_menu(p, &game, &menu);
      refresh(p, game.sprite);
      game.x = -1;
      while (++game.x < WIDTH)
	{
	  wall = calcul_dist(&game.pos, &game.dir,
			     set_vectorf(game.plane.x * (2 * game.x / (float)WIDTH - 1),
					 game.plane.y * (2 * game.x / (float)WIDTH - 1)), p->map);
	  wall.x = game.x;
	  draw_line_wall(wall, p->framebuffer, game.image, game.pos);
	}
      radar(game.pos, p);
      draw_crosshair(p->framebuffer, sfWhite);
      keyboard(&game.pos, &game.dir, &game.plane, p->map);
      hud_inv(game.sprite, game.texture, p, &game.hud);
      action(&game.pos, &game.dir, game.hud, p->map);
    }
}

int			main(int ac, char **av)
{
  t_play		p;
  sfMusic		*ma_musique;

  if (ac != 3)
    return (84);
  srand(time(NULL));
  p.window = create_window("Benki 3D", WIDTH, HEIGHT);
  p.sprite = sfSprite_create();
  p.texture = sfTexture_create(WIDTH, HEIGHT);
  p.framebuffer = my_framebuffer_create(WIDTH, HEIGHT);
  sfSprite_setTexture(p.sprite, p.texture, sfTrue);
  p.map = map_create(av);
  ma_musique = sfMusic_createFromFile("music.ogg");
  sfMusic_setLoop(ma_musique, 1);
  sfMusic_play(ma_musique);
  p.map[2][2] = 48;
  play(&p);
  if (p.window == NULL)
    return (84);
  sfRenderWindow_destroy(p.window);
  return (0);
}
