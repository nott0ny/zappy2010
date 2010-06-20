/*
** graphic_checks.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Sun Jun 20 04:04:39 2010 amine mouafik
** Last update Sun Jun 20 08:08:54 2010 amine mouafik
*/

#include <stdlib.h>

#include "types.h"
#include "graphic.h"

int	convert_direction(int direction)
{
  int	converted;

  converted = 1;
  converted = (direction == 0) ? 3 : converted;
  converted = (direction == 1) ? 4 : converted;
  converted = (direction == 2) ? 1 : converted;
  converted = (direction == 3) ? 2 : converted;
  return (converted);
}

static ushort	player_exists(t_env *e, char *cmd)
{
  int		player_fd;
  char		*player;
  t_players	*current;

  player_fd = 0;
  current = e->clients;
  player = get_args(cmd);
  player++;
  if (player)
    player_fd = atoi(player);
  if (player_fd > 0)
    while (current)
      {
	if (current->fd_associate == player_fd)
	  return (0);
	current = current->next;
      }
  return (1);
}

static ushort	case_exists(t_env *e, char *cmd)
{
  char		*coordinate;
  int		pos;

  pos = atoi((coordinate = get_args(cmd)));
  if (!(pos >= 0 && pos < e->params->width))
    return (1);
  pos = atoi(get_args(coordinate));
  if (!(pos >= 0 && pos < e->params->height))
    return (1);
  return (0);
}

ushort	check_graphic_player(t_env *e, char *cmd)
{
  if (cmd_count(cmd) == 1)
    if (player_exists(e, cmd) == 0)
      return (0);
  return (1);
}

ushort	check_graphic_case(t_env *e, char *cmd)
{
  if (cmd_count(cmd) == 2)
    if (case_exists(e, cmd) == 0)
      return (0);
  return (1);
}
