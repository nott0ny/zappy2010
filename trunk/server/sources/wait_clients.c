/*
** wait_clients.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Mon Jun 14 14:53:48 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

#include "server.h"
#include "utils.h"

static void	init_timeout(t_env *e)
{
  e->network->timeout.tv_sec = 1;
  e->network->timeout.tv_usec = 0;
}

static void	init_fds(t_env *e)
{
  int		cur;

  cur = 0;
  FD_ZERO(&e->network->r);
  FD_ZERO(&e->network->w);
  while (cur < e->network->max_fd_used + 1)
    {
      if (!e->network->fdt[cur])
	{
	  cur++;
	  continue;
	}
      if (e->network->fdt[cur]->type & T_READ)
	FD_SET(cur,&e->network->r);
      if (e->network->fdt[cur]->type & T_WRITE)
	FD_SET(cur,&e->network->w);
      cur++;
    }
}

static void	watch_fds(t_env *e)
{
  int		cur;

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

int	wait_clients(t_env *e)
{
  int  	nfds;

  while (42)
    {
      init_timeout(e);
      init_fds(e);
      nfds = (int)_X((void *)-1,
		     (void *)select(e->network->max_fd_used + 1,
				    &e->network->r, &e->network->w,
				    0, &e->network->timeout), "select");
      if (nfds)
	watch_fds(e);
      execute_stack(e);
    }
  return (0);
}
