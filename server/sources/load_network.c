/*
** load_network.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:55:53 2010 amine mouafik
** Last update Mon Jun  7 16:03:32 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include "server.h"

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
  network->timeout.tv_sec = TIMEOUT;
  network->timeout.tv_usec = 0;
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
