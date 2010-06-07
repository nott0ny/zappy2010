/*
** manage_fdts.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 14:48:48 2010 amine mouafik
** Last update Mon Jun  7 16:03:30 2010 amine mouafik
*/

#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

void		search_max_fd(t_network *e)
{
  struct rlimit	rlp;

  getrlimit(RLIMIT_NOFILE,&rlp);
  if (e->op_flags & OP_U)
    {
      rlp.rlim_cur = rlp.rlim_max;
      if ( (setrlimit(RLIMIT_NOFILE,(struct rlimit *)&rlp)) < 0)
	perror("ARRG setrlimit");
    }
  getrlimit(RLIMIT_NOFILE,&rlp);
  e->max_fd = rlp.rlim_cur;
  if (e->op_flags & OP_V)
    fprintf(stderr,"[verb: max fd = %d]\n",(int)rlp.rlim_cur);
}

void	alloc_fd(t_network *network, int fd)
{
  network->fdt[fd] = xmalloc(sizeof(*network->fdt[fd]));
  memset(network->fdt[fd], 0, sizeof(*network->fdt[fd]));
}

void	alloc_fdt(t_network *network)
{
  network->fdt = xmalloc(network->max_fd * sizeof(**network->fdt));
  memset(network->fdt, 0, network->max_fd * sizeof(**network->fdt));
}

void	set_max_fd(t_network *network, int fd)
{
  int	cur;

  cur = fd - 1;
  while (!network->fdt[cur])
    cur--;
  network->max_fd_used = cur;
}

void	close_fd(t_network *network, int fd)
{
  free(network->fdt[fd]);
  network->fdt[fd] = 0;
  close(fd);
  if (network->max_fd_used == fd)
    set_max_fd(network, fd);
}
