/*
** wait_clients.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Mon Jun  7 16:03:31 2010 amine mouafik
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int	wait_clients(t_env *e)
{
  int	nfds;

  while (42)
    {
      init_fds(e);
      nfds = select(e->network->max_fd_used + 1, &e->network->r, &e->network->w, 0, 0);
      if (nfds)
	watch_fds(e);
      else
	{
	  perror("ARRG select");
	  exit(1);
	}
    }
  return 0;
}
