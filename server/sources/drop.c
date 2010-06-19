/*
** drop.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:34:03 2010 amine mouafik
*/

#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"
#include "answers.h"
#include "drop.h"

void	drop_object(t_env *e, t_players *player)
{
  char	*object;
  t_map	*w;

  w = e->world;
  object = get_args(e->execution->cmd);
  if ((strcmp(object, "nourriture") == 0) && player->bag->food)
    {
      w->map[player->posx][player->posy].food++;
      player->bag->food--;
      rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
      if (!player->bag->food)
	{
	  clean_player(e, player);
	  return ;
	}
    }
  else if ((strcmp(object, "linemate") == 0) && player->bag->linemate)
    {
      w->map[player->posx][player->posy].linemate++;
      player->bag->linemate--;
      rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
    }
  else if ((strcmp(object, "deraumere") == 0) && player->bag->deraumere)
    {
      w->map[player->posx][player->posy].deraumere++;
      player->bag->deraumere--;
      rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
    }
  else if ((strcmp(object, "sibur") == 0) && player->bag->sibur)
    {
      w->map[player->posx][player->posy].sibur++;
      player->bag->sibur--;
      rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
    }
  else if ((strcmp(object, "mendiane") == 0) && player->bag->mendiane)
    {
      w->map[player->posx][player->posy].mendiane++;
      player->bag->mendiane--;
      rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
    }
  else if ((strcmp(object, "phiras") == 0) && player->bag->phiras)
    {
      w->map[player->posx][player->posy].phiras++;
      player->bag->phiras--;
      rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
    }
  else if ((strcmp(object, "thystame") == 0) && player->bag->thystame)
    {
      w->map[player->posx][player->posy].thystame++;
      player->bag->thystame--;
      rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
    }
  else
    rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}
