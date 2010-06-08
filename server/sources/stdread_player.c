/*
** stdread_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun  7 16:03:31 2010 amine mouafik
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "x.h"

t_players	*get_player_byfd(t_env *e, int fd)
{
  t_players	*player;

  player = e->clients;
  while (player)
    {
      if (fd == player->fd_associate)
	break;
      player = player->next;
    }
  return (player);
}

int	get_player_message(char **buf, int fd)
{
  int	len;

  *buf = Xmalloc(READ_SIZE * sizeof(*buf));
  X(NULL, memset(*buf, 0, READ_SIZE * sizeof(*buf)), "memset");
  len = (int)X((void *)-1, (void *)recv(fd, *buf, READ_SIZE, 0), "recv");
  return (len);
}

int	check_player_cmd(t_env *e, t_players *player, char *cmd)
{
  e = e;
  player = player;
  cmd = cmd;
  return (0);
}
