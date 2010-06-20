/*
** clean_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun 14 14:52:14 2010 amine mouafik
** Last update Sun Jun 20 15:04:07 2010 amine mouafik
*/

#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "ringbuffer.h"
#include "answers.h"
#include "graphic.h"
#include "utils.h"
#include "clean_player.h"

void		free_player(t_players *flush)
{
  free(flush->wr_rb->buffer);
  free(flush->rd_rb->buffer);
  free(flush->wr_rb);
  free(flush->rd_rb);
  free(flush->bag);
  free(flush);
}

void		clean_graphic(t_env *e, t_graphics *graphic)
{
  t_graphics	*flush;
  t_graphics	*current;

  flush = graphic;
  current = e->graphics;
  if (flush != current)
    {
      while (current->next &&
	     current->next->fd_associate != flush->fd_associate)
	current = current->next;
      current->next = flush->next;
    }
  else
    e->graphics = current->next;
  free(flush);
}

static void	dead(t_env *e, t_players *player)
{
  char		buff[WR_SIZE];

  sprintf(buff, "pdi %d\n", player->fd_associate);
  send_graphic(e, NULL, buff);
  send(player->fd_associate, DEAD, DEAD_LEN, 0);
}

void		clean_player(t_env *e, t_players *player)
{
  t_players	*flush;
  t_players	*current;

  dead(e, player);
  close_fd(e->network, player->fd_associate);
  player->stacklast = NULL;
  flush = player;
  if (flush->id_team > 0)
    {
      e->world->map[player->posx][player->posy].nb_player--;
      remove_player_stack(e->execution, player);
    }
  current = e->clients;
  if (current != flush)
    {
      while (current->next && current->next != flush)
	current = current->next;
      current->next = flush->next;
    }
  else
    e->clients = current->next;
  if (flush->id_team < 0)
    clean_graphic(e, get_graphic_byfd(e, flush->fd_associate));
  free_player(flush);
}
