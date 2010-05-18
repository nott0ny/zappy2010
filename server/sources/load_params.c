/*
** load_params.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Wed May  5 17:27:30 2010 amine mouafik
** Last update Thu May 13 16:47:36 2010 amine mouafik
*/

#include <stdio.h>
#include "server.h"

int		view_params(t_params *params)
{
  t_teams	*teams;

  teams = params->teams;
  printf("%sInitializing Zappy Server ...\n" \
	 "Configuration : Max (%d) WorldX(%d) WorldY(%d) T(%d)\n" \
	 "Teams :\n", GREEN, params->maxclient, params->width, params->height,
	 params->time);
  printf("\tName(%s) Max(%d)\n", teams->name, params->maxclient);
  while ((teams = teams->next))
    printf("\tName(%s) Max(%d)\n", teams->name, params->maxclient);
  printf("%s", WHITE);
  return (0);
}

t_params	*load_params(char **argv)
{
  t_params	*params;

  params = xmalloc(sizeof(t_params));
  init_params(params);
  get_params(argv, params);
  view_params(params);
  if (check_params(params))
    return (NULL);
  return (params);
}
