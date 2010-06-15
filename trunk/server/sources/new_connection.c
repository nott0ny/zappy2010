/*
** new_connection.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:03:47 2010 amine mouafik
** Last update Thu Jun 10 19:42:54 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"
#include "utils.h"

void			new_connection(t_env *e, ushort fd_conn)
{
  struct sockaddr_in	name;
  socklen_t		namelen;
  ushort       		fd;
  char			addr[4];

  namelen = sizeof(name);
  fd = (int)X(-1, accept((int)fd_conn, (struct sockaddr *)&name, &namelen),
	      "accept");
  memcpy(&addr, &name.sin_addr.s_addr, sizeof(name.sin_addr.s_addr));
  alloc_fd(e->network, fd);
  e->network->fdt[fd]->type |= T_WRITE;
  e->network->fdt[fd]->in.f = stdread;
  e->network->fdt[fd]->out.f = stdwrite;
  e->network->max_fd_used = MAX(e->network->max_fd_used, fd);
  add_player(e, fd);
}
