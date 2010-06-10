/*
** get_params.c for  in /u/all/roux_a/cu/rendu/c/zappy/zappy2010/serveur/sources
** 
** Made by alban roux
** Login   <roux_a@epitech.net>
** 
** Started on  Tue May  4 22:17:56 2010 alban roux
** Last update Mon Jun  7 16:03:33 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "x.h"

static void	get_teams_name(char **av, int *i, t_params *server)
{
  int		size;
  t_teams	*elem;

  size = 1;
  while (av[++(*i)] && strcmp(av[(*i)], "-p") && strcmp(av[(*i)], "-x")
	 && strcmp(av[(*i)], "-n") && strcmp(av[(*i)], "-n")
	 && strcmp(av[(*i)], "-c") && strcmp(av[(*i)], "-t"))
    {
      elem = Xmalloc(sizeof(t_teams));
      elem->name = X(NULL, (void *)strdup(av[(*i)]), "strdup");
      elem->next = server->teams;
      server->teams = elem;
      size++;
    }
  (*i) -= size;
}

void	get_params(char **av, t_params *server)
{
  int	i;

  i = 0;
  while (av[++i + 1])
    if (strcmp(av[i], "-p"))
      if (strcmp(av[i], "-x"))
	if (strcmp(av[i], "-y"))
	  if (strcmp(av[i], "-n"))
	    if (strcmp(av[i], "-c"))
	      {
		if (strcmp(av[i], "-t") == 0)
		  server->time = atoi(av[i + 1]);
	      }
	    else
	      server->maxclient = atoi(av[i + 1]);
	  else
	    get_teams_name(av, &i, server);
	else
	  server->height = atoi(av[i + 1]);
      else
	server->width = atoi(av[i + 1]);
    else
      server->port = atoi(av[i + 1]);
}
