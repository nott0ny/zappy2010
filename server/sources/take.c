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

#include "types.h"
#include "fdts.h"
#include "objects.h"
#include "ringbuffer.h"
#include "answers.h"
#include "take.h"

extern char	*gl_objects[8];

ushort	update_aftertake(int object, t_map *w, t_players *player)
{
  if (object == NOURRITURE && w->map[player->posx][player->posy].food)
    {
      w->map[player->posx][player->posy].food--;
      player->bag->food++;
    }
  else if (object == LINEMATE && w->map[player->posx][player->posy].linemate)
    {
      w->map[player->posx][player->posy].linemate--;
      player->bag->linemate++;
    }
  else if (object == DERAUMERE && w->map[player->posx][player->posy].deraumere)
    {
      w->map[player->posx][player->posy].deraumere--;
      player->bag->deraumere++;
    }
  else if (object == SIBUR && w->map[player->posx][player->posy].sibur)
    {
      w->map[player->posx][player->posy].sibur--;
      player->bag->sibur++;
    }
  else if (object == MENDIANE && w->map[player->posx][player->posy].mendiane)
    {
      w->map[player->posx][player->posy].mendiane--;
      player->bag->mendiane++;
    }
  else if (object == PHIRAS && w->map[player->posx][player->posy].phiras)
    {
      w->map[player->posx][player->posy].phiras--;
      player->bag->phiras++;
    }
  else if (object == THYSTAME && w->map[player->posx][player->posy].thystame)
    {
      w->map[player->posx][player->posy].thystame--;
      player->bag->thystame++;
    }
  else
    return (1);
  return (0);
}

void	take_object(t_env *e, t_players *player)
{
  char	*object;
  t_map	*w;
  int	i;

  i = -1;
  w = e->world;
  object = get_args(e->execution->cmd);
  while (gl_objects[++i])
    if (strcmp(gl_objects[i], object) == 0)
      {
	if (update_aftertake(i, w, player) == 0)
	  rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
	else
	  break ;
	e->network->fdt[player->fd_associate]->type |= T_WRITE;
	return ;
      }
  rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}
