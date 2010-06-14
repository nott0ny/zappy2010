/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun 14 12:33:50 2010 amine mouafik
*/

#include <string.h>
#include <stdio.h>

#include "server.h"
#include "utils.h"

static int	check_team_exists(t_teams *teams, char *team)
{
  t_teams	*current;

  current = teams;
  while (current)
    {
      if (strcmp(team, current->name) == 0)
	return (current->id_team);
      current = current->next;
    }
  return (0);
}

static int	check_team_slots(t_players *clients, int maxclient, int id_team)
{
  t_players	*current;
  int		slots;

  slots = 0;
  current = clients;
  while (current)
    {
      if (id_team)
	if (id_team == current->id_team)
	  slots++;
      current = current->next;
    }
  if (slots < maxclient)
    return (1);
  return (0);
}

int	check_player_team(t_env *e, t_players *player, char *cmd)
{
  int	id_team;

  if (!player->id_team)
    if ((id_team = check_team_exists(e->params->teams, cmd)))
      if (check_team_slots(e->clients, e->params->maxclient, id_team))
	player->id_team = id_team;
  if (!player->id_team)
    return (1);
  printf("%s[%d] Joined team #%d.%s\n",
	 YELLOW, player->fd_associate, id_team, WHITE);
  return (1);
}
