/*
** check_object_arg.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:51:50 2010 amine mouafik
*/

#include <string.h>
#include <stdio.h>

#include "server.h"

static char	*cmd_object_retrieve(char *cmd)
{
  int		i;
  char		*object;

  i = -1;
  object = cmd;
  while (*(object + ++i))
    if (*(object + i) == ' ')
      break;
  object = (char *)(object + i + 1);
  return (object);
}

static int	cmd_object_exists(char *cmd)
{
  int		i;
  char		*object;
  char		*objects[] = {
    "food", "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame", 0
  };

  i = -1;
  object = cmd_object_retrieve(cmd);
  while (objects[++i])
    if (strcmp(objects[i], object) == 0)
      return (0);
  return (-1);
}

static int	cmd_object_count(char *cmd)
{
  int		argc;
  int		i;

  i = -1;
  argc = 0;
  while (cmd[++i])
    if (cmd[i] == ' ')
      argc++;
  return (argc);
}

int		check_object_arg(char *cmd)
{
  if (cmd_object_count(cmd) == 1)
    if (cmd_object_exists(cmd) == 0)
      return (0);
  return (-1);
}
