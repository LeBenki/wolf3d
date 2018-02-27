/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/lucas99.06/CPool_Day09/task03
** 
** Made by Lucas Benkemoun
** Login   <lucas99.06@epitech.net>
** 
** Started on  Fri Oct 14 09:51:37 2016 Lucas Benkemoun
** Last update Sun Jan 15 17:48:47 2017 Lucas Benkemoun
*/

#include "line.h"

int	condition(char c)
{
  if (c == '\n')
    return (0);
  else
    return (1);
}

int	compte_mot(char *str)
{
  int	i;
  int	mot;

  mot = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (condition(str[i]) == 1 && condition(str[i + 1]) == 0)
	mot++;
      i++;
    }
  return (mot + 1);
}

char	**my_str_to_wordtab(char *str, int flag)
{
  int	i;
  int	j;
  int	lettre;
  char	**tab;

  tab = malloc(sizeof(str) * (compte_mot(str) + 1));
  1 ? j = 0, i = -1, lettre = 0 : 0;
  while (str[++i] != 0)
    {
      if (condition(str[i + 1]) != 1 && condition(str[i]) == 1)
	{
	  tab[j] = malloc(sizeof(str) * (i - lettre + 1));
	  1 ? my_strncpy(tab[j], str + lettre, i - lettre + 1, flag), j++ : 0;
	}
      if (condition(str[i]) != 1)
	lettre = i + 1;
    }
  if (str[i - 1] != '\n')
    {
      tab[j] = malloc(sizeof(str) * (i - lettre + 1));
      my_strncpy(tab[j], str + lettre, i - lettre + 1, flag);
      j++;
    }
  tab[j] = NULL;
  return (tab);
}
