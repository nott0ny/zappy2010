/*
** drop.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 12:24:24 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "objects.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "answers.h"
#include "drop.h"

extern char	*gl_objects[8];

static void	display_drop(int object, t_map casecontent,
			     t_players *player, t_env *e)
{
  char		buff[WR_SIZE];

  sprintf(buff, "pdr %d %d\nbct %d %d %d %d %d %d %d %d %d\n",
	  player->fd_associate, object, player->posx, player->posy,
	  casecontent.food, casecontent.linemate, casecontent.deraumere,
	  casecontent.sibur, casecontent.mendiane, casecontent.phiras,
	  casecontent.thystame);
  send_graphic(e, NULL, buff);
}

static void	drop(ushort *mapcount, ushort *bagcount)
{
  *mapcount++;
  *bagcount--;
}

static ushort	update_afterdrop(int object, t_map *w,
				 t_players *player, t_env *e)
{
  if (object == NOURRITURE && player->bag->food)
    {
      drop(&w->map[player->posx][player->posy].food, &player->bag->food);
      if (!player->bag->food)
	{
	  clean_player(e, player);
	  return (0);
	}
    }
  else if (object == LINEMATE && player->bag->linemate)
    drop(&w->map[player->posx][player->posy].linemate, &player->bag->linemate);
  else if (object == DERAUMERE && player->bag->deraumere)
    drop(&w->map[player->posx][player->posy].deraumere, &player->bag->deraumere);
  else if (object == SIBUR && player->bag->sibur)
    drop(&w->map[player->posx][player->posy].sibur, &player->bag->sibur);
  else if (object == MENDIANE && player->bag->mendiane)
    drop(&w->map[player->posx][player->posy].mendiane, &player->bag->mendiane);
  else if (object == PHIRAS && player->bag->phiras)
    drop(&w->map[player->posx][player->posy].phiras, &player->bag->phiras);
  else if (object == THYSTAME && player->bag->thystame)
    drop(&w->map[player->posx][player->posy].thystame, &player->bag->thystame);
  else
    return (1);
  return (0);
}

void	drop_object(t_env *e, t_players *player)
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
	if (update_afterdrop(i, w, player, e) == 0)
	  {
	    rb_write(player->wr_rb, SUCCESS, SUCCESS_LEN);
	    display_drop(i, w->map[player->posx][player->posy],
			 player, e);
	  }
	else
	  break;
	e->network->fdt[player->fd_associate]->type |= T_WRITE;
	return ;
      }
  rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}
