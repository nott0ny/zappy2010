/*
** expulse.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 09:57:11 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "answers.h"
#include "utils.h"

static ushort	expulse_player(t_env *e, t_players *player, t_players *cur)
{
  static ushort	i;
  char		buff[WR_SIZE];

  X(NULL, memset(buff, 0, sizeof(char) * WR_SIZE),  "memset");
  sprintf(buff, "pex #%d\n", player->fd_associate);
  send_graphic(e, NULL, buff);
  if (player->direction == LEFT)
    cur->posx = (--cur->posx < 0) ? e->params->width - 1 : cur->posx;
  else if (player->direction == RIGHT)
    cur->posx = (++cur->posx >=  e->params->width) ? 0 : cur->posx;
  else if (player->direction == UP)
    cur->posy = ((--cur->posy) < 0) ? e->params->height - 1 : cur->posy;
  else if (player->direction == DOWN)
    cur->posy = ((++cur->posy) >=  e->params->height) ? 0 : cur->posy;
  X(NULL, memset(buff, 0, sizeof(char) * WR_SIZE),  "memset");
  sprintf(buff, "ppo #%d %d %d %d\n", cur->fd_associate,
	  cur->posx, cur->posy, cur->direction);
  send_graphic(e, NULL, buff);
  return (++i);
}

void		expulse(t_env *e, t_players *player)
{
  t_players	*cur;
  int		i;

  i = 0;
  cur = e->clients;
  while (cur)
    {
      if (cur->posx == player->posx && cur->posy == player ->posy
	  && player->fd_associate != cur->fd_associate)
	if ((i = expulse_player(e, player, cur)) == 1)
	  if (i == 1)
	    rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
      cur = cur->next;
    }
  if (!i)
    rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}
