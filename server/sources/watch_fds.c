/*
** watch_fds.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 15:15:49 2010 amine mouafik
** Last update Mon Jun  7 16:03:30 2010 amine mouafik
*/

#include "server.h"

int	init_fds(t_env *e)
{
  int	cur;

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
  return (0);
}

void	watch_fds(t_env *e)
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
