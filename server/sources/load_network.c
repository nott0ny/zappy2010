/*
** load_network.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:55:53 2010 amine mouafik
** Last update Mon Jun 14 15:59:24 2010 amine mouafik
*/

/*#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>*/

#include "types.h"
#include "utils.h"
#include "load_network.h"

static ushort	init_fdt(t_network *network)
{
  search_max_fd(network);
  network->fdt = Xmalloc(network->max_fd * sizeof(**network->fdt));
  return (0);
}

t_network	*load_network(t_params *params)
{
  t_network	*network;

  network = Xmalloc(sizeof(t_network));
  init_fdt(network);
  init_connect_socket(network, params);
  return (network);
}
