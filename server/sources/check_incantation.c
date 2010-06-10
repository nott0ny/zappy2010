/*
** check_incantation.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 20:05:06 2010 amine mouafik
*/

#include <string.h>

#include "server.h"
#include "utils.h"

typedef struct	s_incantation {
  int   	elevation;
  int   	players;
  int		linemate;
  int   	deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
}		t_incantation;

static void	init_incantation_have(t_incantation *have)
{
  have->elevation = 0;
  have->players = 0;
  have->linemate = 0;
  have->deraumere = 0;
  have->sibur = 0;
  have->mendiane = 0;
  have->phiras = 0;
  have->thystame = 0;
}

static t_incantation   	*check_incantation_have(t_env *e, t_players *player)
{
  t_players		*players;
  t_incantation		*have;

  players = e->clients;
  have = Xmalloc(sizeof(t_incantation));
  init_incantation_have(have);
  while (players)
    {
      if (players->posx == player->posx && players->posy == player->posy
	  && players->level == player->level)
	{
	  have->linemate += players->bag->linemate;
	  have->deraumere += players->bag->deraumere;
	  have->sibur += players->bag->sibur;
	  have->mendiane += players->bag->mendiane;
	  have->phiras += players->bag->phiras;
	  have->thystame += players->bag->thystame;
	  have->players++;
	}
      players = players->next;
    }
  return (have);
}

static int	check_incantation_requirements(t_incantation *requirements,
					       t_incantation *have, int i)
{
  if (requirements[i].players == have->players)
    if (requirements[i].linemate == have->linemate)
      if (requirements[i].deraumere == have->deraumere)
	if (requirements[i].sibur == have->sibur)
	  if (requirements[i].mendiane == have->mendiane)
	    if (requirements[i].phiras == have->phiras)
	      if (requirements[i].thystame == have->thystame)
		return (0);
  return (-1);
}

int		check_incantation(t_env *e, t_players *player)
{
  int		i;
  t_incantation	*have;
  t_incantation	requirements[] = {
    {2, 1, 1, 0, 0, 0, 0, 0},
    {3, 2, 1, 1, 1, 0, 0, 0},
    {4, 2, 2, 0, 1, 0, 2, 0},
    {5, 4, 1, 1, 2, 0, 1, 0},
    {6, 4, 1, 2, 1, 3, 0, 0},
    {7, 6, 1, 2, 3, 0, 1, 0},
    {8, 6, 2, 2, 2, 2, 2, 1},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  i = -1;
  have = check_incantation_have(e, player);
  while (requirements[++i].elevation)
    if ((i - 1) == player->level)
      {
	if (check_incantation_requirements(requirements, have, i) == 0)
	  return (0);
	return (-1);
      }
  return (-1);
}
