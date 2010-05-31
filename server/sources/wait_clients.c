/*
** wait_clients.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Mon May 31 15:21:24 2010 alban roux
*/

#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

/**/
#define MAX(a,b)	( (a>b)?(a):(b) )
void	alloc_fd(t_network *e,int fd);

void	std_read(__attribute__((unused))t_env *e, int cur)
{
  printf("in str_read %d\n", cur);
}

void	do_fd(t_env *e)
{
  int	cur;

  cur = 0;
  while (cur < e->network->max_fd_used + 1)
    {
      if (!e->network->fdt[cur])
	{
	  cur++;
	  continue;
	}
      if (FD_ISSET(cur,&e->network->r))
	e->network->fdt[cur]->in.f(e, cur);
      if (FD_ISSET(cur,&e->network->w))
	e->network->fdt[cur]->out.f(e, cur);
      cur++;
    }
}

static void	init_fd_set(t_network *e)
{
  int		cur;

  cur = 0;
  FD_ZERO(&e->r);
  FD_ZERO(&e->w);
  while (cur < e->max_fd_used + 1)
    {
      if (!e->fdt[cur])
	{
	  cur++;
	  continue;
	}
      if (e->fdt[cur]->type & T_READ)
	  FD_SET(cur,&e->r);
      if (e->fdt[cur]->type & T_WRITE)
	  FD_SET(cur,&e->w);
      cur++;
    }
}

void	set_max_fd_used(t_network *e, int fd)
{
  e->max_fd_used = MAX(e->max_fd_used, fd);
}

void			new_connection(t_env *e,int fd_conn)
{
  struct sockaddr_in	name;
  socklen_t		namelen;
  int			fd;
  char			addr[4];

  namelen = sizeof(name);
  fd = accept(fd_conn,(struct sockaddr *)&name, &namelen);
  memcpy(&addr,&name.sin_addr.s_addr,sizeof(name.sin_addr.s_addr));
  if (fd < 0)
    {
      perror("ARRG accept");
      exit(1);
    }
  alloc_fd(e->network, fd);
  e->network->fdt[fd]->type |= T_READ;
  e->network->fdt[fd]->in.f = std_read;
  set_max_fd_used(e->network, fd);
  write(fd, "BIENVENUE\n", strlen("BIENVENUE\n"));
}

int	wait_clients(t_env *e)
{
  int	nfds;

  while (42)
    {
      init_fd_set(e->network);
      nfds = select(e->network->max_fd_used + 1, &e->network->r, &e->network->w, 0, 0);
      if (nfds)
	do_fd(e);
      else
	{
	  perror("ARRG select");
	  exit(1);
	}
    }
  return 0;
}
