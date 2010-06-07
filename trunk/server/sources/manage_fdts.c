/*
** manage_fdts.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 14:48:48 2010 amine mouafik
** Last update Mon Jun  7 16:03:30 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

void		search_max_fd(t_network *e)
{
  struct rlimit	rlp;

  X((void *)-1, (void *)getrlimit(RLIMIT_NOFILE,&rlp), "getrlimit");
  if (e->op_flags & OP_U)
    {
      rlp.rlim_cur = rlp.rlim_max;
      X((void *)-1, (void *)setrlimit(RLIMIT_NOFILE,(struct rlimit *)&rlp), "setrlimit");
    }
  X((void *)-1, (void *)getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
  e->max_fd = rlp.rlim_cur;
  if (e->op_flags & OP_V)
    fprintf(stderr,"[verb: max fd = %d]\n",(int)rlp.rlim_cur);
}

void	alloc_fd(t_network *network, int fd)
{
  network->fdt[fd] = Xmalloc(sizeof(*network->fdt[fd]));
  X(NULL, memset(network->fdt[fd], 0, sizeof(*network->fdt[fd])), "memset");
}

void	alloc_fdt(t_network *network)
{
  network->fdt = Xmalloc(network->max_fd * sizeof(**network->fdt));
  X(NULL, memset(network->fdt, 0, network->max_fd * sizeof(**network->fdt)), "memset");
}

void	close_fd(t_network *network, int fd)
{
  int	cur;

  free(network->fdt[fd]);
  network->fdt[fd] = 0;
  X((void *)-1, (void *)close(fd), "close");
  if (network->max_fd_used == fd)
    {
      cur = fd - 1;
      while (!network->fdt[cur])
	cur--;
      network->max_fd_used = cur;
    }
}
