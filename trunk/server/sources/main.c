/*
** main.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 20:55:54 2010 amine mouafik
** Last update Mon Jun 14 17:53:48 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

#include "server.h"
#include "utils.h"

static ushort	server(char **argv)
{
  t_env		*e;

  e = Xmalloc(sizeof(t_env));
  if ((e->params = load_params(argv)))
    if ((e->map = load_map(e->params)))
      if ((e->network = load_network(e->params)))
	if (!wait_clients(e))
	  return (0);
  return (1);
}

int	main(int argc, char **argv)
{
  if (argc == 1)
    printf("Usage: ./server [-p port] [-x largeur] [-y hauteur] " \
	   "[-n equipe_1 equipe_2 (...)] [-c nombre de client] " \
	   "[-t temps]\n");
  else
    server(argv);
  return (0);
}
