/*
** get_params.c for  in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:17:56 2010 amine mouafik
** Last update Sun Jun 20 10:19:51 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "utils.h"

static void	get_teams_name(char **av, int *i, t_params *server)
{
  ushort       	size;
  t_teams	*elem;
  static int	id_team = 1;

  size = 1;
  while (av[++(*i)] && strcmp(av[(*i)], "-p") && strcmp(av[(*i)], "-x")
	 && strcmp(av[(*i)], "-n") && strcmp(av[(*i)], "-n")
	 && strcmp(av[(*i)], "-c") && strcmp(av[(*i)], "-t"))
    {
      elem = Xmalloc(sizeof(t_teams));
      elem->id_team = id_team++;
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
