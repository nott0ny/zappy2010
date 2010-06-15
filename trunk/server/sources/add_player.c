/*
** add_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Mon Jun 14 15:31:54 2010 amine mouafik
*/

#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"
#include "ringbuffer.h"
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
  bag->food = 0;
}

static void	create_player_list(t_env *e, ushort fd)
{
  t_players	*player;

  srand(time(NULL));
  player = Xmalloc(sizeof(t_players));
  player->bag = Xmalloc(sizeof(t_bag));
  init_player_bag(player->bag);
  rb_init(&(player->wr_rb), BUF_SIZE);
  rb_init(&(player->rd_rb), BUF_SIZE);
  player->fd_associate = fd;
  player->id_team = 0;
  player->level = 1;
  player->posx = generate(e->params->width);
  player->posy = generate(e->params->height);
  player->direction = generate(4);
  printf("Direction : %d\n", player->direction);
  player->stacklast = NULL;
  player->next = NULL;
  e->clients = player;
  e->map[player->posx][player->posy].nb_player++;
  rb_write(player->wr_rb, MSG_CONNECT, strlen(MSG_CONNECT));
}

static void	add_player_tolist(t_env *e, ushort fd)
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
  player->level = 1;
  player->posx = generate(e->params->width);
  player->posy = generate(e->params->height);
  player->direction = generate(4);
  player->stacklast = NULL;
  player->next = e->clients;
  e->clients = player;
  e->map[player->posx][player->posy].nb_player++;
  rb_write(player->wr_rb, MSG_CONNECT, strlen(MSG_CONNECT));
}

void	add_player(t_env *e, ushort fd)
{
  if (e->clients == NULL)
    create_player_list(e, fd);
  else
    add_player_tolist(e, fd);
}
