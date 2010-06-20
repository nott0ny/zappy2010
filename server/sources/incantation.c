/*
** incantation.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 10:16:21 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "answers.h"
#include "incantation.h"
#include "utils.h"

static ushort	display_incantation(t_env *e, t_players *player)
{
  char		buff[WR_SIZE];

  sprintf(buff, "pie %d %d %d\n", player->posx, player->posy, 1);
  send_graphic(e, NULL, buff);
  return (1);
}

void		incantation(t_env *e, t_players *player)
{
  char		buff[WR_SIZE];
  t_players	*players;
  int		levelup;

  levelup = 0;
  players = e->clients;
  if (check_incantation(e, player, 1) == 0)
    levelup = display_incantation(e, player);
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
