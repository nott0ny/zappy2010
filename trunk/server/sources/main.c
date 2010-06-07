/*
** main.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 20:55:54 2010 amine mouafik
** Last update Mon Jun  7 15:56:53 2010 amine mouafik
*/

#include <stdio.h>
#include "server.h"

static int	server(char **argv)
{
  t_env		*e;

  e = xmalloc(sizeof(t_env));
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
    printf("Usage: ./serveur [-p port] [-x largeur] [-y hauteur] " \
	   "[-n equipe_1 equipe_2 (...)] [-c nombre de client] " \
	   "[-t temps]\n");
  else
    server(argv);
  return (0);
}
