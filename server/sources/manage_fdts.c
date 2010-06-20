/*
** manage_fdts.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:48:48 2010 amine mouafik
** Last update Sun Jun 20 01:41:50 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "utils.h"

void		search_max_fd(t_network *e)
{
  struct rlimit	rlp;

  X(-1, getrlimit(RLIMIT_NOFILE,&rlp), "getrlimit");
  rlp.rlim_cur = rlp.rlim_max;
  X(-1, setrlimit(RLIMIT_NOFILE,(struct rlimit *)&rlp),
    "setrlimit");
  X(-1, getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
  e->max_fd = rlp.rlim_cur;
}

void		close_fd(t_network *network, short fd)
{
  ushort	cur;

  free(network->fdt[fd]);
  network->fdt[fd] = 0;
  X(-1, close(fd), "close");
  if (network->max_fd_used == fd)
    {
      cur = fd - 1;
      while (!network->fdt[cur])
	cur--;
      network->max_fd_used = cur;
    }
}
