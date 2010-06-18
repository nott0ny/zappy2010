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

#include "types.h"
#include "check_player_cmd.h"

ushort	check_player_cmd(t_env *e, t_players *player,
			 char *cmd, ushort len, ushort id)
{
  if (id == PRENDRE || id == POSE)
    return (check_object_args(cmd));
  else if (id == BROADCAST)
    return (check_msg_args(cmd));
  else if (len == (int)strlen(cmd))
    {
      if (id == INCANTATION)
	return(check_incantation(e, player));
      else
	return (0);
    }
  return (1);
}
