/*
** parsing.c for wireframe in /home/lucas99.06/Epitech/Semester1/Graph_Prog/wireframe/src
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Tue Dec  6 20:35:43 2016 Lucas Benkemoun
** Last update Sun Jan 15 18:13:30 2017 Lucas Benkemoun
*/

#include "line.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		**map_create(char **av)
{
  int		fd;
  char		*buff;
  int		size;
  char		**tab;

  fd = open(av[1], O_RDONLY);
  if (av[2][0] < '1' || av[2][0] > '3')
    exit(84);
  if (fd == -1)
    {
      write(2, "wolf3d: ", 8);
      write(2, (av[1]), my_strlen(av[1]));
      write(2, ": No such file or directory\n", 28);
      exit(84);
    }
  buff = malloc(4096 * sizeof(char));
  size = read(fd, buff, 4096);
  buff[size] = '\0';
  close(fd);
  tab = my_str_to_wordtab(buff, av[2][0] - '0');
  free(buff);
  return (tab);
}
