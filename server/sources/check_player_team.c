/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun  7 16:03:31 2010 amine mouafik
*/

#include <string.h>
#include <stdio.h>
#include "server.h"
#include "colors.h"

static int	check_team_exists(t_teams *teams, char *team)
{
  t_teams	*current;

  current = teams;
  while (current)
    {
      if (strcmp(team, current->name) == 0)
	return (0);
      current = current->next;
    }
  return (-1);
}

static int	check_team_slots(t_players *clients, int maxclient, char *team)
{
  t_players	*current;
  int		slots;

  slots = 0;
  current = clients;
  while (current)
    {
      if (current->team_name)
	if (strcmp(team, current->team_name) == 0)
	  slots++;
      current = current->next;
    }
  if (slots < maxclient)
    return (0);
  return (-1);
}

int	check_player_team(t_env *e, t_players *player, char *cmd)
{
  if (player->team_name == NULL)
    if (check_team_exists(e->params->teams, cmd) == 0)
      if (check_team_slots(e->clients, e->params->maxclient, cmd) == 0)
	player->team_name = (char *)strdup(cmd);
  if (player->team_name == NULL)
    return (1);
  printf("%s[%d] Joined team '%s'.%s\n",
	 YELLOW, player->fd_associate, cmd, WHITE);
  return (1);
}
