/*
** clean_exit.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun 14 16:08:37 2010 amine mouafik
** Last update Mon Jun 14 16:28:11 2010 amine mouafik
*/

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
      free(clients->bag);
      free(clients);
    }
}

static void	free_background(t_params *params, t_map **map, t_network *network)
{
  int		i;
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
  i = -1;
  while (map[++i])
    free(map[i]);
  free(map);
  i = -1;
  while (network->fdt[++i])
    free(network->fdt[i]);
  free(network->fdt);
}

void	clean_exit(t_env *e)
{
  free_background(e->params, e->map, e->network);
  free_clients(e->clients);
  free_stack(e->execution);
}
