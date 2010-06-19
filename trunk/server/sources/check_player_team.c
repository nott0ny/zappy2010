/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Sun Jun 20 00:32:56 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "stack.h"
#include "ringbuffer.h"
#include "utils.h"
#include "check_player_team.h"

static void	joined(t_env *e, t_players *player, int id_team,
		       char *team, int slots)
{
  char		buff[WR_SIZE];

  player->id_team = id_team;
  sprintf(buff, "%d\n%d %d\n", slots - 1,
	  e->params->width, e->params->height);
  rb_write(player->wr_rb, buff, strlen(buff));
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
  add_stack_healthcare(e, player, HEALTHCARE, HEALTHCARE_T);
  printf("%sPlayer #%d successfully joined team '%s'.%s\n",
	 GREEN, player->fd_associate, team, WHITE);
}

static void	no_slots(t_players *player, char *team)
{
  printf("%sPlayer #%d tried to join team '%s'.\n" \
	 "No slots available for this team.%s\n",
	 YELLOW, player->fd_associate, team, WHITE);
}

static void	no_such_team(t_players *player, char *team)
{
  printf("%sPlayer #%d tried to join team '%s'.\n" \
	 "No such team ...%s\n",
	 RED, player->fd_associate, team, WHITE);
}

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
  ushort	id_team;
  int		slots;

  if (!player->id_team)
    {
      if ((id_team = check_team_exists(e->params->teams, cmd)))
	{
	  if ((slots = get_free_slots_byteam(e, id_team)))
	    {
	      joined(e, player, id_team, cmd, slots);
	      return (0);
	    }
	  else
	    no_slots(player, cmd);
	}
      else
	no_such_team(player, cmd);
    }
  if (!player->id_team)
    return (1);
  return (1);
}
