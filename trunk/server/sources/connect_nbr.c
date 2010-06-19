/*
** connect_nbr.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 00:37:40 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"

int		get_free_slots_byteam(t_env *e, int id_team)
{
  t_players	*current;
  int       	slots;

  slots = 0;
  current = e->clients;
  while (current)
    {
      if (id_team)
	if (id_team == current->id_team)
	  slots++;
      current = current->next;
    }
  if (slots < e->params->maxclient)
    return (e->params->maxclient - slots);
  return (0);
}

void	connect_nbr(t_env *e, t_players *player)
{
  char	buff[WR_SIZE];
  int	free_slots;

  free_slots = get_free_slots_byteam(e, player->id_team);
  sprintf(buff, "%d\n", free_slots);
	  rb_write(player->wr_rb, buff, strlen(buff));
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}
