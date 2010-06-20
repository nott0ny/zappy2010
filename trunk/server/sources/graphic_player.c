/*
** graphic_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Sun Jun 20 03:25:35 2010 amine mouafik
** Last update Sun Jun 20 11:44:36 2010 amine mouafik
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "ringbuffer.h"
#include "graphic.h"

void		player_pos(t_env *e, t_players *graphic, char *cmd)
{
  char		buff[WR_SIZE];
  t_players	*current;
  char		*player;
  int		fd_player;

  player = get_args(cmd);
  fd_player = atoi(player);
  current = get_player_byfd(e, fd_player);
  sprintf(buff, "ppo %d %d %d %d\n", fd_player,
	  current->posx, current->posy, current->direction);
  send_graphic(e, graphic, buff);
}

void		player_level(t_env *e, t_players *graphic, char *cmd)
{
  char		buff[WR_SIZE];
  t_players	*current;
  char		*player;
  int		fd_player;

  player = get_args(cmd);
  fd_player = atoi(player);
  current = get_player_byfd(e, fd_player);
  sprintf(buff, "plv %d %d\n", fd_player, current->level);
  send_graphic(e, graphic, buff);

}

void		player_inventory(t_env *e, t_players *graphic, char *cmd)
{
  char		buff[WR_SIZE];
  t_players	*current;
  char		*player;
  int		fd_player;

  player = get_args(cmd);
  fd_player = atoi(player);
  current = get_player_byfd(e, fd_player);
  sprintf(buff, "pin %d %d %d %d %d %d %d %d %d %d\n", fd_player,
	  current->posx, current->posy, current->bag->food,
	  current->bag->linemate, current->bag->deraumere,
	  current->bag->sibur, current->bag->mendiane,
	  current->bag->phiras, current->bag->thystame);
  send_graphic(e, graphic, buff);
}
