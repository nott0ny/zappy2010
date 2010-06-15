/*
** get_object.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:34:03 2010 amine mouafik
*/

#include "server.h"

char		*get_object(char *cmd)
{
  ushort       	i;
  char		*object;

  i = -1;
  object = cmd;
  while (*(object + ++i))
    if (*(object + i) == ' ')
      break;
  object = (char *)(object + i + 1);
  return (object);
}
