/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun 14 14:38:45 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "server.h"
#include "ringbuffer.h"
#include "utils.h"

static ushort	check_team_exists(t_teams *teams, char *team)
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
  int       	slots;

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
    return (maxclient - slots);
  return (0);
}

ushort		check_player_team(t_env *e, t_players *player, char *cmd)
{
  char		buff[512];
  ushort	id_team;
  int		slots;

  if (!player->id_team)
    if ((id_team = check_team_exists(e->params->teams, cmd)))
      if ((slots = check_team_slots(e->clients, e->params->maxclient, id_team)))
	{
	  player->id_team = id_team;
	  sprintf(buff, "%d\n%d\n", player->posx, player->posy);
	  rb_write(player->wr_rb, buff, strlen(buff));
	  e->network->fdt[player->fd_associate]->type |= T_WRITE;
	  return (0);
	}
  if (!player->id_team)
    return (1);
  return (1);
}
