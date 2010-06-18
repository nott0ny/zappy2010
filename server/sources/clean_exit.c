/*
** clean_exit.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun 14 16:08:37 2010 amine mouafik
** Last update Tue Jun 15 12:18:05 2010 amine mouafik
*/

#include <sys/socket.h>
#include <stdlib.h>

#include "server.h"

static void	free_stack(t_stack *execution)
{
  t_stack	*flush;

  flush = execution;
  while (flush)
    {
      execution = flush;
      flush = flush->next;
      free(execution->cmd);
      free(execution);
    }
}

static void	free_clients(t_players *clients)
{
  t_players	*flush;

  flush = clients;
  while (flush)
    {
      clients = flush;
      flush = flush->next;
      free(clients->wr_rb->buffer);
      free(clients->rd_rb->buffer);
      free(flush->wr_rb);
      free(flush->rd_rb);
      free(clients->bag);
      free(clients);
    }
}

static void	free_background(t_params *params, t_map *world, t_network *fdts)
{
  ushort       	i;
  t_teams	*flush;

  flush = params->teams;
  while (flush)
    {
      params->teams = flush;
      flush = params->teams->next;
      free(params->teams->name);
      free(params->teams);
    }
  free(params);
  i = 0;
  while (world->map[i])
    free(world->map[i++]);
  free(world->map);
  free(world);
  i = 0;
  while (fdts->fdt[i])
    free(fdts->fdt[i++]);
  free(fdts->fdt);
  free(fdts->timeout);
}

static void	close_connections(t_network *network)
{
  ushort       	cur;

  cur = 0;
  while(cur < network->max_fd_used + 1)
    {
      if (!network->fdt[cur])
	{
	  cur++;
	  continue;
	}
      network->fdt[cur]->type |= T_FREE;
      shutdown(cur, SHUT_RDWR);
      cur++;
    }
}

void	clean_exit(t_env *e)
{
  close_connections(e->network);
  free_background(e->params, e->world, e->network);
  free_clients(e->clients);
  free_stack(e->execution);
}
