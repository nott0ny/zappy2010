/*
** expulse.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Mon Jun 14 15:31:54 2010 amine mouafik
*/

#include <string.h>

#include "server.h"
#include "ringbuffer.h"

static ushort	expulse_player(t_env *e, t_players *player, t_players *cur)
{
  static ushort	i;

  if (player->direction == UP)
    cur->posx = (--cur->posx < 0) ? e->params->width - 1 : cur->posx;
  else if (player->direction == DOWN)
    cur->posx = (++cur->posx >=  e->params->width) ? 0 : cur->posx;
  else if (player->direction == RIGHT)
    cur->posy = ((--cur->posy) < 0) ? e->params->height - 1 : cur->posy;
  else if (player->direction == LEFT)
    cur->posy = ((++cur->posy) >=  e->params->height) ? 0 : cur->posy;
  return (i++);
}

void		expulse(t_env *e, t_players *player)
{
  t_players	*cur;

  cur = e->clients;
  while (cur)
    {
      if (cur->posx == player->posx && cur->posy == player ->posy
	  && player->fd_associate != cur->fd_associate)
	if (expulse_player(e, player, cur) == 1)
	  rb_write(player->wr_rb, MSG_SUCCESS,
		   strlen(MSG_SUCCESS));
      cur = cur->next;
    }
  rb_write(player->wr_rb, MSG_FAILURE, strlen(MSG_FAILURE));
}
