/*
** check_player_cmd.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Mon Jun 14 13:09:50 2010 amine mouafik
*/

#include <string.h>

#include "server.h"
#include "check_player_cmd.h"

ushort	check_player_cmd(t_env *e, t_players *player,
			 char *cmd, ushort len, ushort id)
{
  if (id == PRENDRE || id == POSE)
    {
      if (check_object_arg(cmd) == 0)
	return (0);
    }
  else if (len == (int)strlen(cmd))
    {
      if (id == INCANTATION)
	if (check_incantation(e, player) == 0)
	  return (0);
	else
	  return (1);
      else
	return (0);
    }
  return (1);
}
