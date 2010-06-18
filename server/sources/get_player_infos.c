/*
** get_player_infos.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun 14 13:49:15 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "stack.h"
#include "ringbuffer.h"
#include "utils.h"

t_stack		*get_player_stacklast_byfd(t_env *e, ushort fd)
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

t_players	*get_player_byfd(t_env *e, ushort fd)
{
  t_players	*player;

  player = e->clients;
  if (player)
    {
      if (fd == player->fd_associate)
	return (player);
      while ((player = player->next))
	if (fd == player->fd_associate)
	  break;
    }
  return (player);
}

ushort	get_player_message(char **buf, ushort fd)
{
  int	len;

  *buf = Xmalloc(READ_SIZE * sizeof(*buf));
  X(NULL, memset(*buf, 0, READ_SIZE * sizeof(*buf)), "memset");
  len = recv(fd, *buf, READ_SIZE, 0);
  return (len);
}
