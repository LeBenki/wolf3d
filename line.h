/*
** line.h for bswireframe in /home/lucas99.06/Epitech/Semester1/Graph_Prog/bswireframe
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Mon Nov 14 10:22:38 2016 Lucas Benkemoun
** Last update Sun Jan 15 17:51:41 2017 Lucas Benkemoun
*/

#ifndef LINE_H_
# define LINE_H_

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef TW
#  define TW 64
# endif

# ifndef TH
#  define TH 64
# endif

typedef struct          s_my_framebuffer
{
  sfUint8*              pixels;
  int                   width;
  int                   height;
}                       t_my_framebuffer;

typedef struct		s_wall
{
  float                 rayDirX;
  float                 rayDirY;
  float			distance;
  int			side;
  int			hit;
  int			x;
  sfVector3f		save;
}			t_wall;

typedef struct          s_play
{
  sfTexture*            texture;
  sfRenderWindow        *window;
  sfSprite*             sprite;
  t_my_framebuffer      *framebuffer;
  char                  **map;
}                       t_play;

typedef struct          s_ray
{
  float			rayDirX;
  float			rayDirY;
  int			mapX;
  int			mapY;
  float			sideDistX;
  float			sideDistY;
  float			deltaDistX;
  float			deltaDistY;
  float			distance;
  int			stepX;
  int			stepY;
}                       t_ray;

typedef struct		s_game
{
  int                   x;
  sfVector2f            pos;
  sfVector2f            plane;
  sfVector2f            dir;
  t_wall                wall;
  sfTexture             **texture;
  sfSprite              *sprite;
  sfImage               **image;
  int                   tex;
  sfSprite              *sprite2;
  int                   hud;
}			t_game;

void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to, sfColor color);
sfRenderWindow		*create_window(char* name, int width, int height);
float			raycast(sfVector2f pos,
				float direction, int **map, sfVector2i mapSize);
sfColor			set_color(sfUint8 r, sfUint8 g, sfUint8 b);
sfVector2i		set_vector(int x, int y);
sfVector2f		set_vectorf(float x, float y);
t_wall			calcul_dist(sfVector2f *pos,
				    sfVector2f *dir, sfVector2f plane, char **map);
char			**map_create(char **av);
char			**my_str_to_wordtab(char *str, int flag);
void			keyboard(sfVector2f *pos,
				 sfVector2f *dir, sfVector2f *plane, char **map);
char			*my_strncpy(char *dest, char *src, int n, int flag);
void			draw_crosshair(t_my_framebuffer *framebuffer, sfColor color);
void			radar(sfVector2f pos, t_play *p);
void			draw_sprite(t_my_framebuffer *framebuffer,
				    t_wall wall, sfImage **image, sfVector2f pos);
void			draw_line_wall(t_wall wall, t_my_framebuffer *framebuffer,
			       sfImage **image, sfVector2f pos);
void			draw_square(t_my_framebuffer *framebuffer, int x, int y,
				    sfColor color);
void                    refresh(t_play *p, sfSprite *sprite);
sfImage			**load_files(sfImage **image);
sfColor			divid_color(sfColor color);
sfTexture		**load_hud(sfTexture **texture);
void                    hud_inv(sfSprite *sprite,
				sfTexture **texture, t_play *p, int *hud);
void			action(sfVector2f *pos,
			       sfVector2f *dir, int hud, char **map);
void            placer(sfVector2f *pos,
		       sfVector2f *dir, int hud, char **map);
void            casser(sfVector2f *pos,
		       sfVector2f *dir, int hud, char **map);

#endif	/* !LINE_H_ */
