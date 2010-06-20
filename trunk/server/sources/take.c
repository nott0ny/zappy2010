/*
** take.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 15:05:15 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "objects.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "answers.h"
#include "take.h"

extern char	*gl_objects[8];

static void	display_take(int object, t_map *world,
			     t_players *player, t_env *e)
{
  char		buff[WR_SIZE];
  t_map		casecontent;

  casecontent = world->map[player->posx][player->posy];
  sprintf(buff, "pgt %d %d\nbct %d %d %d %d %d %d %d %d %d\n",
	  player->fd_associate, object, player->posx, player->posy,
	  casecontent.food, casecontent.linemate, casecontent.deraumere,
	  casecontent.sibur, casecontent.mendiane, casecontent.phiras,
	  casecontent.thystame);
  send_graphic(e, NULL, buff);
}

static void	take(ushort *mapcount, ushort *bagcount)
{
  (*mapcount)--;
  (*bagcount)++;
}

static ushort	update_aftertake(int object, t_map *w, t_players *player)
{
  if (object == NOURRITURE && w->map[player->posx][player->posy].food)
    take(&w->map[player->posx][player->posy].food, &player->bag->food);
  else if (object == LINEMATE && w->map[player->posx][player->posy].linemate)
    take(&w->map[player->posx][player->posy].linemate, &player->bag->linemate);
  else if (object == DERAUMERE && w->map[player->posx][player->posy].deraumere)
    take(&w->map[player->posx][player->posy].deraumere,
	 &player->bag->deraumere);
  else if (object == SIBUR && w->map[player->posx][player->posy].sibur)
    take(&w->map[player->posx][player->posy].sibur, &player->bag->sibur);
  else if (object == MENDIANE && w->map[player->posx][player->posy].mendiane)
    take(&w->map[player->posx][player->posy].mendiane, &player->bag->mendiane);
  else if (object == PHIRAS && w->map[player->posx][player->posy].phiras)
    take(&w->map[player->posx][player->posy].phiras, &player->bag->phiras);
  else if (object == THYSTAME && w->map[player->posx][player->posy].thystame)
    take(&w->map[player->posx][player->posy].thystame, &player->bag->thystame);
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
	  {
	    rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
	    display_take(i, w,  player, e);
	  }
	else
	  break;
	e->network->fdt[player->fd_associate]->type |= T_WRITE;
	return ;
      }
  rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}
