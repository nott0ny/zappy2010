/*
** get_player_infos.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Sun Jun 20 01:41:36 2010 amine mouafik
*/

#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "stack.h"
#include "utils.h"

t_stack		*get_player_stacklast_byfd(t_env *e, short fd)
{
  t_stack      	*stack;

  stack = e->execution;
  while (stack)
    {
      if (stack->fd_player == fd && strcmp(HEALTHCARE, stack->cmd))
	return (stack);
      stack = stack->next;
    }
  return (NULL);
}

t_players	*get_player_byfd(t_env *e, short fd)
{
  t_players	*player;

  player = e->clients;
  if (player)
    {
      while (player)
	{
	  if (fd == player->fd_associate)
	    break;
	  player = player->next;
	}
    }
  return (player);
}
