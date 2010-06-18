/*
** clean_player.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun 14 14:52:14 2010 amine mouafik
** Last update Mon Jun 14 15:34:09 2010 amine mouafik
*/

#include <sys/socket.h>
#include <stdlib.h>

#include "types.h"
#include "clean_player.h"

void		clean_player(t_env *e, t_players *player)
{

  t_players	*flush;
  t_players	*current;

  shutdown(player->fd_associate, SHUT_RDWR);
  close_fd(e->network, player->fd_associate);
  player->stacklast = NULL;
  /*  remove_player_stack(e->execution, player); */
  flush = player;
  current = e->clients;
  if (current != flush)
    {
      while (current->next && current->next != flush)
	current = current->next;
      current->next = flush->next;
    }
  else
    e->clients = current->next;
  free(flush->wr_rb->buffer);
  free(flush->rd_rb->buffer);
  free(flush->wr_rb);
  free(flush->rd_rb);
  free(flush->bag);
  free(flush);
}
