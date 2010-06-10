/*
** get_player_infos.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Thu Jun 10 20:15:04 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "x.h"

t_players	*get_player_byfd(t_env *e, int fd)
{
  t_players	*player;

  player = e->clients;
  if (fd == player->fd_associate)
    return (player);
  while ((player = player->next))
    if (fd == player->fd_associate)
      break;
  return (player);
}

int	get_player_message(char **buf, int fd)
{
  int	len;

  *buf = Xmalloc(READ_SIZE * sizeof(*buf));
  X(NULL, memset(*buf, 0, READ_SIZE * sizeof(*buf)), "memset");
  len = recv(fd, *buf, READ_SIZE, 0);
  return (len);
}
