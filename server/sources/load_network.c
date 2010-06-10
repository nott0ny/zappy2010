/*
** load_network.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:55:53 2010 amine mouafik
** Last update Thu Jun 10 19:33:24 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#include "server.h"
#include "utils.h"

static int	init_fdt(t_network *network)
{
  search_max_fd(network);
  alloc_fdt(network);
  return (0);
}

static t_network	*init_network(t_params *params)
{
  t_network		*network;

  network = Xmalloc(sizeof(*network));
  X(NULL, memset(network, 0, sizeof(*network)), "memset");
  network->port = params->port;
  return (network);
}

t_network	*load_network(t_params *params)
{
  t_network	*network;

  network = init_network(params);
  init_fdt(network);
  init_connect_socket(network);
  return (network);
}
