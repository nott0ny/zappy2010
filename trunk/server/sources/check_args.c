/*
** check_args.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 18:06:16 2010 amine mouafik
*/

#include <string.h>

#include "types.h"
#include "check_args.h"

char	*gl_objects[] = {
  "nourriture",
  "linemate",
  "deraumere",
  "sibur",
  "mendiane",
  "phiras",
  "thystame",
  0
};

static ushort	cmd_object_exists(char *cmd)
{
  ushort       	i;
  char		*object;

  i = -1;
  object = get_args(cmd);
  while (gl_objects[++i])
    if (strcmp(gl_objects[i], object) == 0)
      return (0);
  return (1);
}

ushort		cmd_count(char *cmd)
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
    if (strncmp(cmd, PREND_SP, strlen(PREND_SP)) == 0 ||
	strncmp(cmd, POSE_SP, strlen(POSE_SP)) == 0)
      if (cmd_object_exists(cmd) == 0)
	return (0);
  return (1);
}

ushort		check_msg_args(char *cmd)
{
  if (cmd_count(cmd) >= 1)
    if (strncmp(cmd, BROADCAST_SP, strlen(BROADCAST_SP)) == 0)
      return (0);
  return (1);
}
