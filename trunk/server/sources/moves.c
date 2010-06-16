/*
** moves.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:34:03 2010 amine mouafik
*/

#include <string.h>

#include "server.h"
#include "ringbuffer.h"
#include "answers.h"

void	go_forward(t_env *e, t_players *player)
{
  e->world->map[player->posx][player->posy].nb_player--;
  if (player->direction == UP)
    player->posx = (++player->posx >=  e->params->width) ? 0 : player->posx;
  else if (player->direction == DOWN)
    player->posx = (--player->posx < 0) ? e->params->width - 1 : player->posx;
  else if (player->direction == LEFT)
    player->posy = (--player->posy < 0) ? e->params->height - 1 : player->posy;
  else if (player->direction == RIGHT)
    player->posy = (++player->posy >= e->params->height) ? 0 : player->posy;
  e->world->map[player->posx][player->posy].nb_player++;
  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
}

void	rotate_left(t_env *e, t_players *player)
{
  e = e;
  if (player->direction == LEFT)
    player->direction = DOWN;
  else
    player->direction--;
  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
}

void	rotate_right(t_env *e, t_players *player)
{
  e = e;
  if (player->direction == DOWN)
    player->direction = LEFT;
  else
    player->direction++;
  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
}
