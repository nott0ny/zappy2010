/*
** wait_clients.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Thu May 13 16:54:11 2010 amine mouafik
*/

#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

void		display_received(int cs)
{
  char		buf[BUFSIZ];
  int		offset;

  offset = read(cs, buf, sizeof(buf));
  if (offset == 0)
    exit(0);
  write(1, buf, offset);
  return ;
}

void		new_client(t_env *e)
{
  t_clients	*client;
  static int	id;

  client = xmalloc(sizeof(t_clients));
  client->cs = e->network->cs;
  client->id = ++id;
  client->players = NULL;
  client->next = e->clients;
  e->clients = client;
  printf("New client pushed : cs(%d) id(%d)\n", client->cs, client->id);
}

int		manage_clients(t_env *e)
{
  fd_set	readf;

  printf("Writing 'BIENVENUE\\n' on %d ...\n", e->clients->cs);
  write(e->clients->cs, "BIENVENUE\n", strlen("BIENVENUE\n"));
  while (1)
    {
      FD_ZERO(&readf);
      FD_SET(e->clients->cs, &readf);
      if (select(e->clients->cs + 1, &readf, NULL, NULL, NULL) < 0)
	manage_clients(e);
      if (FD_ISSET(e->clients->cs, &readf))
	display_received(e->clients->cs);
    }
  return (0);
}

int		wait_clients(t_env *e)
{
  fd_set	readf;

  FD_ZERO(&readf);
  e->clients = xmalloc(sizeof(t_clients));
  if ((e->network->cs = accept(e->network->s,
			       (struct sockaddr *)&e->network->client,
			       &e->network->csl)) > 0)
    new_client(e);
  manage_clients(e);
  return (0);
}
