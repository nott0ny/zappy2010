/*
** load_params.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Wed May  5 17:27:30 2010 amine mouafik
** Last update Mon Jun 14 14:44:59 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

#include "server.h"
#include "load_params.h"
#include "utils.h"

static int	init_params(t_params *params)
{
  params->port = DEFAULT_PORT;
  params->width = DEFAULT_WIDTH;
  params->height = DEFAULT_HEIGHT;
  params->teams = NULL;
  params->maxclient = DEFAULT_CLIENT;
  params->time = DEFAULT_TIME;
  return (0);
}

static int	view_params(t_params *params)
{
  t_teams	*teams;

  teams = params->teams;
  printf("%sInitializing Zappy Server ...\n" \
	 "Configuration : Max (%d) WorldX(%d) WorldY(%d) T(%d)\n" \
	 "Teams :\n",
	 GREEN, params->maxclient, params->width, params->height,
	 params->time);
  while (teams)
    {
      printf("\tName(%s) Max(%d)\n", teams->name, params->maxclient);
      teams = teams->next;
    }
  printf("%s", WHITE);
  return (0);
}

t_params	*load_params(char **argv)
{
  t_params	*params;

  params = Xmalloc(sizeof(t_params));
  init_params(params);
  get_params(argv, params);
  if (check_params(params))
    return (NULL);
  view_params(params);
  return (params);
}
