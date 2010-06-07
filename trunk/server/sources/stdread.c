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
#include "colors.h"
#include "x.h"

void		stdread(t_env *e,int fd)
{
  t_players	*tmp;
  char		*buf;
  int		len;

  buf = Xmalloc(READ_SIZE * sizeof(*buf));
  X(NULL, memset(buf, 0, READ_SIZE * sizeof(*buf)), "memset");
  len = (int)X((void *)-1, (void *)recv(fd, buf, READ_SIZE, 0), "recv");
  if (len <= 0)
    close_fd(e->network, fd);
  else
    {
      tmp = e->clients;
      while (tmp && (tmp->fd_associate != fd))
	tmp = tmp->next;
      if (tmp)
	printf("%sI'm client %d\nmy team is %s%s\n", YELLOW,
	       tmp->fd_associate, tmp->team_name, WHITE);
      printf("%sRECU CMD : %s%s\n", YELLOW, buf, WHITE);
    }
  free(buf);
}
