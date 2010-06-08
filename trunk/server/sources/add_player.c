/*
** add_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Mon Jun  7 16:03:33 2010 amine mouafik
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "ringbuffer.h"
#include "x.h"

static void	create_player_list(t_env *e, int fd)
{
  t_players	*player;
  
  player = Xmalloc(sizeof(*player));
  rb_init(&(player->wr_rb), BUF_SIZE);
  rb_init(&(player->rd_rb), BUF_SIZE);
  player->fd_associate = fd;
  rb_write(player->wr_rb, (unsigned char *)MSG_CO, strlen(MSG_CO));
  player->bag = Xmalloc(sizeof(player->bag));
  player->next = NULL;
  e->clients = player;
}

static void	add_player_tolist(t_env *e, int fd)
{
  t_players	*player;

  player = Xmalloc(sizeof(t_players));
  rb_init(&player->wr_rb, BUF_SIZE);
  rb_init(&player->rd_rb, BUF_SIZE);
  player->fd_associate = fd;
  rb_write(player->wr_rb, (unsigned char *)MSG_CO, strlen(MSG_CO));
  player->bag = Xmalloc(sizeof(player->bag));
  player->next = e->clients;
  e->clients = player;
}

void	add_player(t_env *e, int fd)
{
  if (e->clients == NULL)
    create_player_list(e, fd);
  else
    add_player_tolist(e, fd);
}
