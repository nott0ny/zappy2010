/*
** incantation.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:34:03 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"
#include "answers.h"
#include "incantation.h"

void		incantation(t_env *e, t_players *player)
{
  char		buff[512];
  t_players	*players;
  int		levelup;

  levelup = 0;
  players = e->clients;
  if (check_incantation(e, player) == 0)
    levelup = 1;
  else
    rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
  while (players && levelup)
    {
      if (players->posx == player->posx && players->posy == player->posy
	  && players->level == player->level)
	{
	  players->level++;
	  sprintf(buff, "niveau actuel : %d\n", players->level);
	  rb_write(players->wr_rb, buff, strlen(buff));
	  e->network->fdt[players->fd_associate]->type |= T_WRITE;
	}
      players = players->next;
    }
}
