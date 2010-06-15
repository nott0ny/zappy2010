/*
** take.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
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

void	take_object(t_env *e, t_players *player)
{
  char *object;

  object = get_object(e->execution->cmd);
  if ((strcmp(object, "nourriture") == 0) && e->map[player->posx][player->posy].food)
    {
      e->map[player->posx][player->posy].food--;
      player->bag->food++;
      rb_write(player->wr_rb, MSG_SUCCESS, strlen(MSG_SUCCESS));
    }
  else if ((strcmp(object, "linemate") == 0) && e->map[player->posx][player->posy].linemate)
    {
      e->map[player->posx][player->posy].linemate--;
      player->bag->linemate++;
      rb_write(player->wr_rb, MSG_SUCCESS, strlen(MSG_SUCCESS));
    }
  else if ((strcmp(object, "deraumere") == 0) && e->map[player->posx][player->posy].deraumere)
    {
      e->map[player->posx][player->posy].deraumere--;
      player->bag->deraumere++;
      rb_write(player->wr_rb, MSG_SUCCESS, strlen(MSG_SUCCESS));
    }
  else if ((strcmp(object, "sibur") == 0) && e->map[player->posx][player->posy].sibur)
    {
      e->map[player->posx][player->posy].sibur--;
      player->bag->sibur++;
      rb_write(player->wr_rb, MSG_SUCCESS, strlen(MSG_SUCCESS));
    }
  else if ((strcmp(object, "mendiane") == 0) && e->map[player->posx][player->posy].mendiane)
    {
      e->map[player->posx][player->posy].mendiane--;
      player->bag->mendiane++;
      rb_write(player->wr_rb, MSG_SUCCESS, strlen(MSG_SUCCESS));
    }
  else if ((strcmp(object, "phiras") == 0) && e->map[player->posx][player->posy].phiras)
    {
      e->map[player->posx][player->posy].phiras--;
      player->bag->phiras++;
      rb_write(player->wr_rb, MSG_SUCCESS, strlen(MSG_SUCCESS));
    }
  else if ((strcmp(object, "thystame") == 0) && e->map[player->posx][player->posy].thystame)
    {
      e->map[player->posx][player->posy].thystame--;
      player->bag->thystame++;
      rb_write(player->wr_rb, MSG_SUCCESS, strlen(MSG_SUCCESS));
    }
  else
    rb_write(player->wr_rb, MSG_FAILURE, strlen(MSG_FAILURE));
}
