/*
** graphic_params.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Sun Jun 20 03:26:42 2010 amine mouafik
** Last update Sun Jun 20 06:16:20 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "ringbuffer.h"
#include "graphic.h"

void		teams_name(t_env *e, t_players *graphic,
			   __attribute__((unused))char *cmd)
{
  char		buff[WR_SIZE];
  t_teams	*current;

  current = e->params->teams;
  while (current)
    {
      sprintf(buff, "tna %s\n", current->name);
      send_graphic(e, graphic, buff);
      current = current->next;
    }
}

void	get_time(t_env *e, t_players *graphic,
		 __attribute__((unused))char *cmd)
{
  char	buff[WR_SIZE];

  sprintf(buff, "sqt %d\n", e->params->time);
  send_graphic(e, graphic, buff);
}

void	set_time(t_env *e, t_players *graphic, char *cmd)
{
  e = e;
  graphic = graphic;
  cmd = cmd;
}
