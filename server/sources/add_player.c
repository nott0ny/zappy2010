/*
** add_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 01:35:39 2010 amine mouafik
*/

#include <time.h>
#include <stdlib.h>

#include "types.h"
#include "ringbuffer.h"
#include "answers.h"
#include "utils.h"

static int	generate(int limit)
{
  int		nb;

  nb = rand() % limit;
  return (nb);
}

static void	init_player_bag(t_bag *bag)
{
  bag->linemate = 0;
  bag->deraumere = 0;
  bag->sibur = 0;
  bag->mendiane = 0;
  bag->phiras = 0;
  bag->thystame = 0;
  bag->food = 10;
}

void	add_player(t_env *e, short fd)
{
  t_players	*player;

  srand(time(NULL));
  player = Xmalloc(sizeof(t_players));
  player->bag = Xmalloc(sizeof(t_bag));
  init_player_bag(player->bag);
  rb_init(&player->wr_rb, BUF_SIZE);
  rb_init(&player->rd_rb, BUF_SIZE);
  player->fd_associate = fd;
  player->id_team = 0;
  player->active = 0;
  player->level = 1;
  player->posx = generate(e->params->width);
  player->posy = generate(e->params->height);
  player->direction = generate(4);
  player->stacksize = 0;
  player->stacklast = NULL;
  player->next = e->clients;
  e->clients = player;
  rb_write(player->wr_rb, CONNECT, CONNECT_LEN);
}
