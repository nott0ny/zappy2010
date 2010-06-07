/*
** add_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Mon Jun  7 16:03:33 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

static void	create_player_list(t_env *e, int fd, char *t_name, int x, int y)
{
  t_players	*player;

  player = Xmalloc(sizeof(*player));
  player->fd_associate = fd;
  player->team_name = Xmalloc(strlen(t_name) * sizeof(*t_name));
  /* CHECK X */
  player->team_name = strcpy(player->team_name, t_name);
  player->posx = x;
  player->posy = y;
  player->next = NULL;
  e->clients = player;
}

static void	add_player_tolist(t_env *e, int fd, char *t_name, int x, int y)
{
  t_players	*new_player;
  t_players	*last_player;

  last_player = e->clients;
  while (last_player->next)
    last_player = last_player->next;
  new_player = Xmalloc(sizeof(*new_player));
  new_player->fd_associate = fd;
  /* CHECK X */
  new_player->team_name = (char *)strdup(t_name);
  new_player->posx = x;
  new_player->posy = y;
  new_player->next = NULL;
  last_player->next = new_player;
}

void	add_player(t_env *e, int fd, char *t_name, int x, int y)
{
  if (e->clients == NULL)
    create_player_list(e, fd, t_name, x, y);
  else
    add_player_tolist(e, fd, t_name, x, y);
}

