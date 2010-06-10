/*
** check_params.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 23:39:46 2010 amine mouafik
** Last update Thu Jun 10 19:34:47 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include "server.h"
#include "check_params.h"
#include "x.h"

static int	check_limits(int nb, int a, int b)
{
  if (b)
    if (nb < a || nb > b)
      return (1);
  if (!b)
    if (nb < a)
      return (1);
  return (0);
}

static int	check_teams_reserved(t_teams *teams)
{
  t_teams	*current;

  current = teams;
  while (current)
    {
      if (!strcmp(current->name, CLIENT_GRAPHIC))
	return (1);
      current = current->next;
    }
  return (0);
}

static int	check_teams_minimum(t_teams *teams)
{
  t_teams	*current;
  int		i;

  i = 0;
  current = teams;
  while (current && ++i)
    current = current->next;
  if (i < 2)
    return (1);
  return (0);
}

static int	check_teams_uniqueness(t_teams *teams)
{
  t_teams	*begin;
  t_teams	*steps;
  t_teams	*current;

  begin = steps = current = teams;
  while (steps)
    {
      while (current)
	{
	  if (current != steps)
	    if (!strcmp(current->name, steps->name))
	      return (1);
	  current = current->next;
	}
      current = begin;
      steps = steps->next;
    }
  return (0);
}

int	check_params(t_params *params)
{
  if (!check_limits(params->width, 1, 0) &&
      !check_limits(params->height, 1, 0))
    if (!check_limits(params->time, 1, 1000000))
      if (!check_teams_reserved(params->teams))
	if (!check_teams_minimum(params->teams))
	  if (!check_teams_uniqueness(params->teams))
	    if (!check_limits(params->maxclient, 1, 0))
	      return (0);
	    else
	      return (_xw(ERR_CLIENT));
	  else
	    return (_xw(ERR_TEAMS));
	else
	  return (_xw(ERR_TEAMS_MIN));
      else
	return (_xw(ERR_TEAMS_RSV));
    else
      return (_xw(ERR_TIME));
  else
    return (_xw(ERR_MAP));
}
