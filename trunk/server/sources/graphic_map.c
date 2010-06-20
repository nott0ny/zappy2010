/*
** graphic_map.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Sun Jun 20 03:23:49 2010 amine mouafik
** Last update Sun Jun 20 06:16:11 2010 amine mouafik
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "ringbuffer.h"
#include "graphic.h"

void	map_size(t_env *e, t_players *graphic,
		 __attribute__((unused))char *cmd)
{
  char	buff[WR_SIZE];

  sprintf(buff, "msz %d %d\n", e->params->width, e->params->height);
  send_graphic(e, graphic, buff);
}

void	case_content(t_env *e, t_players *graphic, char *cmd)
{
  char	buff[WR_SIZE];
  char	*pos;
  int	x;
  int	y;

  pos = get_args(cmd);
  x = atoi(pos);
  pos = get_args(pos);
  y = atoi(pos);
  sprintf(buff, "bct %d %d %d %d %d %d %d %d %d\n",
	  x, y, e->world->map[x][y].food, e->world->map[x][y].linemate,
	  e->world->map[x][y].deraumere, e->world->map[x][y].sibur,
	  e->world->map[x][y].mendiane, e->world->map[x][y].phiras,
	  e->world->map[x][y].thystame);
  send_graphic(e, graphic, buff);
}

void	map_content(t_env *e, t_players *graphic,
		    __attribute__((unused))char *cmd)
{
  char	buff[WR_SIZE];
  int	x;
  int	y;

  x = -1;
  while (++x < e->params->height)
    {
      y = -1;
      while (++y < e->params->width)
	{
	  sprintf(buff, "bct %d %d %d %d %d %d %d %d %d\n",
		  x, y, e->world->map[x][y].food, e->world->map[x][y].linemate,
		  e->world->map[x][y].deraumere, e->world->map[x][y].sibur,
		  e->world->map[x][y].mendiane, e->world->map[x][y].phiras,
		  e->world->map[x][y].thystame);
	  send_graphic(e, graphic, buff);
	}
    }
}
