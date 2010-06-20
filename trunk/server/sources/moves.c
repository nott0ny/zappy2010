/*
** moves.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 12:01:45 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "answers.h"

void	go_forward(t_env *e, t_players *player)
{
  char	buff[WR_SIZE];

  e->world->map[player->posx][player->posy].nb_player--;
  if (player->direction == RIGHT)
    player->posx = (++player->posx >=  e->params->width) ? 0 : player->posx;
  else if (player->direction == LEFT)
    player->posx = (--player->posx < 0) ? e->params->width - 1 : player->posx;
  else if (player->direction == UP)
    player->posy = (--player->posy < 0) ? e->params->height - 1 : player->posy;
  else if (player->direction == DOWN)
    player->posy = (++player->posy >= e->params->height) ? 0 : player->posy;
  e->world->map[player->posx][player->posy].nb_player++;
  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
  sprintf(buff, "ppo %d %d %d %d\n", player->fd_associate,
	  player->posx, player->posy, player->direction);
  send_graphic(e, NULL, buff);
}

void	rotate_left(t_env *e, t_players *player)
{
  char	buff[WR_SIZE];

  if (player->direction == UP)
    player->direction = LEFT;
  else
    player->direction--;
  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
  sprintf(buff, "ppo %d %d %d %d\n", player->fd_associate,
	  player->posx, player->posy, player->direction);
  send_graphic(e, NULL, buff);
}

void	rotate_right(t_env *e, t_players *player)
{
  char	buff[WR_SIZE];

  if (player->direction == LEFT)
    player->direction = UP;
  else
    player->direction++;
  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
  sprintf(buff, "ppo %d %d %d %d\n", player->fd_associate,
	  player->posx, player->posy, player->direction);
  send_graphic(e, NULL, buff);
}
