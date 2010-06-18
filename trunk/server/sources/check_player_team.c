/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Fri Jun 18 15:59:04 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "stack.h"
#include "ringbuffer.h"
#include "utils.h"
#include "check_player_team.h"

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

ushort		check_player_team(t_env *e, t_players *player, char *cmd)
{
  char		buff[512];
  ushort	id_team;
  int		slots;

  if (!player->id_team)
    if ((id_team = check_team_exists(e->params->teams, cmd)))
      if ((slots = get_free_slots_byteam(e, id_team)))
	{
	  player->id_team = id_team;
	  sprintf(buff, "%d\n%d %d\n", slots - 1,
		  e->params->width, e->params->height);
	  rb_write(player->wr_rb, buff, strlen(buff));
	  e->network->fdt[player->fd_associate]->type |= T_WRITE;
	  add_stack_healthcare(e, player, HEALTHCARE, HEALTHCARE_T);
	  return (0);
	}
  if (!player->id_team)
    return (1);
  return (1);
}
