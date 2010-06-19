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

void		stdwrite(t_env *e, int fd)
{
  t_players	*player;
  char		stdwrite[WR_SIZE];
  short       	len;

  player = get_player_byfd(e, fd);
  if (player)
    {
      while ((len = rb_has_cmd(player->wr_rb)) > 0)
	{
	  rb_read(player->wr_rb, stdwrite, len);
	  if ((len = send(fd, stdwrite, strlen(stdwrite), 0)) <= 0)
	    {
	      clean_player(e, player);
	      return ;
	    }
	  verbose(1, len, stdwrite, player);
	}
      e->network->fdt[fd]->type |= T_READ;
      e->network->fdt[fd]->type &= T_READ;
    }
}
