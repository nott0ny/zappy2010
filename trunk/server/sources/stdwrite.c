/*
** stdwrite.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Fri Jun 18 23:31:28 2010 amine mouafik
*/

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"
#include "utils.h"
#include "stdwrite.h"

static void	stdwbose(char *stdwrite, ushort len, t_players *player)
{
  stdwrite[len - 1] = '\0';
  printf("[->] Sent to #%d : %s%s%s\n",
	 player->fd_associate, PURPLE, stdwrite, WHITE);
}

void		stdwrite(t_env *e, int fd)
{
  t_players	*player;
  char		stdwrite[256];
  ushort       	len;

  player = get_player_byfd(e, fd);
  if (player)
    {
      while ((len = rb_has_cmd(player->wr_rb)) > 0)
	{
	  rb_read(player->wr_rb, stdwrite, len);
	  len = (int)X(-1, send(fd, stdwrite, strlen(stdwrite), 0), "send");
	  stdwbose(stdwrite, len, player);
	}
      e->network->fdt[fd]->type |= T_READ;
      e->network->fdt[fd]->type &= T_READ;
    }
}
