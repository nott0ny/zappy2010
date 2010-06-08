/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun  7 16:03:31 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "ringbuffer.h"
#include "colors.h"
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

int		get_player_message(char **buf, int fd)
{
  int		len;

  *buf = Xmalloc(READ_SIZE * sizeof(*buf));
  X(NULL, memset(*buf, 0, READ_SIZE * sizeof(*buf)), "memset");
  len = (int)X((void *)-1, (void *)recv(fd, *buf, READ_SIZE, 0), "recv");
  return (len);
}

void		manage_player_cmd(t_env *e, int fd, int cmdlen)
{
  return ;
}

void		stdread(t_env *e,int fd)
{
  t_players	*player;
  char		*buf;
  int		len;

  len = get_player_message(&buf, fd);
  if (len <= 0)
    close_fd(e->network, fd);
  else
    {
      player = get_player_byfd(e, fd);
      if (player)
	{
	  rb_write(player->rd_rb, (unsigned char *)buf, len);
	  if ((len = rb_has_cmd(player->rd_rb)) > 0)
	    manage_player_cmd(e, fd, len);
	  else if (len == -1)
	    close_fd(e->network, fd);
	}
    }
  free(buf);
}
