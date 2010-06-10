/*
** stdwrite.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun  7 16:03:31 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "ringbuffer.h"
#include "colors.h"
#include "x.h"

void		stdwrite(t_env *e, int fd)
{
  t_players	*player;
  char		send_cmd[256];
  int		len;

  player = get_player_byfd(e, fd);
  if (player)
    {
      if ((len = rb_has_cmd(player->wr_rb)) > 0)
	{
	  rb_read(player->wr_rb, (unsigned char *)send_cmd, len);
	  X((void *)-1, (void *)write(fd, send_cmd, strlen(send_cmd)), "write");
	}
      e->network->fdt[fd]->type |= T_READ;
    }
}
