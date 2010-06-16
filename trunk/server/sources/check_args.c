/*
** check_args.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:51:50 2010 amine mouafik
*/

#include <string.h>

#include "server.h"

static ushort	cmd_object_exists(char *cmd)
{
  ushort       	i;
  char		*object;
  char		*objects[] = {
    "food", "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame", 0
  };

  i = -1;
  object = get_args(cmd);
  while (objects[++i])
    if (strcmp(objects[i], object) == 0)
      return (0);
  return (1);
}

static ushort	cmd_count(char *cmd)
{
  ushort       	argc;
  ushort       	i;

  i = -1;
  argc = 0;
  while (cmd[++i])
    if (cmd[i] == ' ')
      argc++;
  return (argc);
}

ushort		check_object_args(char *cmd)
{
  if (cmd_count(cmd) == 1)
    if (cmd_object_exists(cmd) == 0)
      return (0);
  return (1);
}

ushort		check_msg_args(char *cmd)
{
  if (cmd_count(cmd) >= 1)
    return (0);
  return (1);
}
