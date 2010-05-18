/*
** load_network.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:55:53 2010 amine mouafik
** Last update Thu May 13 16:50:46 2010 amine mouafik
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"

t_network	*load_network(t_params *params)
{
  t_network	*network;

  network = xmalloc(sizeof(t_network));
  network->s = socket(PF_INET, SOCK_STREAM, 0);
  network->port = params->port;
  network->server.sin_family = AF_INET;
  network->server.sin_port = htons(network->port);
  network->server.sin_addr.s_addr = INADDR_ANY;
  bind(network->s, (struct sockaddr*)&network->server, sizeof(network->server));
  listen(network->s, 5);
  network->csl = sizeof(network->client);
  printf("%sListening on port %d ...%s\n", GREEN, network->port, WHITE);
  return (network);
}
