/*
** wait_clients.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Mon Jun 14 18:22:10 2010 amine mouafik
*/

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>

#include "types.h"
#include "fdts.h"
#include "utils.h"
#include "wait_clients.h"

static void		init_timeout(t_env *e)
{
  struct timeval	*timestamp;

  free(e->network->timeout);
  timestamp = Xmalloc(sizeof(struct timeval));
  if (e->execution)
    {
      gettimeofday(timestamp, NULL);
      timestamp->tv_sec = e->execution->timestamp.tv_sec - timestamp->tv_sec;
    }
  else
    timestamp = NULL;
  e->network->timeout = timestamp;
}

static void	init_fds(t_env *e)
{
  ushort       	cur;

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
  ushort       	cur;

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

ushort		wait_clients(t_env *e)
{
  ushort 	nfds;

  while (42)
    {
      init_timeout(e);
      init_fds(e);
      nfds = (int)_X(-1, select(e->network->max_fd_used + 1,
				&e->network->r, &e->network->w,
				0, e->network->timeout), "select");
      if (nfds)
	watch_fds(e);
      execute_stack(e);
    }
  clean_exit(e);
  return (0);
}
