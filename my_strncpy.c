/*
** my_strncpy.c for my_strncpy in /home/lucas99.06/CPool_Day06
** 
** Made by Lucas Benkemoun
** Login   <lucas99.06@epitech.net>
** 
** Started on  Mon Oct 10 09:40:38 2016 Lucas Benkemoun
** Last update Sun Jan 15 17:51:17 2017 Lucas Benkemoun
*/

#include "line.h"

char    *my_strncpy(char *dest, char *src, int n, int flag)
{
  int i;

  i = 0;
  while (n > 0 && *(src + i))
    {
      if (*(src + i) == '2')
	*(dest + i) = *(src + i);
      else if (flag == 2)
	if (!(rand()%3 % 3))
	  *(dest + i) = rand()%10 + '0';
	else
	  *(dest + i) = 48;
      else if (flag == 3)
	*(dest + i) = 48;
      else
	*(dest + i) = *(src + i);
      i++;
      n--;
    }
  *(dest + i) = '\0';
  return (dest);
}
