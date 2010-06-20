/*
** broadcast.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 16:17:35 2010 amine mouafik
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "answers.h"
#include "broadcast.h"
#include "utils.h"

static void	get_first_case(t_env *e, t_players *dest, int *cx, int *cy)
{
  *cx = dest->posx;
  *cy = dest->posy;
  if (dest->direction == UP)
    *cx = (*cx == 0) ? e->params->width - 1 : *cx - 1;
  else if (dest->direction == DOWN)
    *cx = (*cx == e->params->width - 1) ? 0 : *cx + 1;
  else if (dest->direction == LEFT)
    *cy = (*cy == 0) ? e->params->height - 1 : *cy - 1;
  else if (dest->direction == RIGHT)
    *cy = (*cy == e->params->height - 1) ? 0 : *cy + 1;
}

static int	get_direction(t_env *e, t_players *dest, int x, int y)
{
  int		cx;
  int		cy;
  int		o;
  int		i;

  cx = 0;
  cy = 0;
  i = 0;
  get_first_case(e, dest, &cx, &cy);
  o = dest->direction;
  while (++i <= 8)
    {
      if ((cx == x) && (cy == y))
	return (i);
      o = (i % 2 == 0) ? o - 1 : o;
      o = (o < DOWN) ? LEFT : o;
      if (o == UP)
	cy = (cy == 0) ? e->params->height - 1 : cy - 1;
      else if (o == DOWN)
	cy = (cy == e->params->height - 1) ? 0 : cy + 1;
      else if (o == LEFT)
	cx = (cx == e->params->width - 1) ? 0 : cx + 1;
      else if (o == RIGHT)
	cx = (cx == 0) ? e->params->width - 1 : cx - 1;
    }
  return (0);
}

static ushort	get_entry_point(t_env *e, t_players *orig, t_players *dest)
{
  int		dx;
  int		dy;

  dx = dest->posx - orig->posx;
  dx = (dx > (e->params->width / 2)) ? dx - e->params->width : dx;
  dx = (dx < (-(e->params->width / 2))) ? dx + e->params->width : dx;
  dy = dest->posy - orig->posy;
  dy = (dy > (e->params->height / 2)) ? dy - e->params->height : dy;
  dy = (dy < (-(e->params->height / 2))) ? dy + e->params->height : dy;
  if (dx >= dy)
    dx = (dx < 0) ? dx + 1 : dx - 1;
  if (dy >= dx)
    dy = (dy < 0) ? dy + 1 : dy - 1;
  dx += orig->posx;
  dy += orig->posy;
  dx = (dx > e->params->width - 1) ? dx - e->params->width : dx;
  dx = (dx < 0) ? dx + e->params->width : dx;
  dy = (dy > e->params->height - 1) ? dy - e->params->height : dy;
  dy = (dy < 0) ? dy + e->params->height : dy;
  return (get_direction(e, dest, dx, dy));
}

void		broadcast(t_env *e, t_players *player)
{
  t_players	*players;
  char		buff[WR_SIZE];
  char		*msg;
  ushort       	k;

  msg = get_args(e->execution->cmd);
  players = e->clients;
  while (players)
    {
      if (players == player || !players->active)
	{
	  players = players->next;
	  continue;
	}
      k = get_entry_point(e, player, players);
      sprintf(buff, "message %d, %s\n", k, msg);
      rb_write(players->wr_rb, buff, strlen(buff));
      e->network->fdt[players->fd_associate]->type |= T_WRITE;
      players = players->next;
    }
  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
  sprintf(buff + strlen(buff), "pbc %d %s\n", player->fd_associate, msg);
  send_graphic(e, NULL, buff);
}

