/*
** execute_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun 14 14:52:14 2010 amine mouafik
** Last update Mon Jun 14 15:34:09 2010 amine mouafik
*/

#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

extern t_cmds gl_cmds[11];

void		remove_player_stack(t_stack *execution, t_players *player)
{
  t_stack	*tmp;

  tmp = execution;
  while (tmp)
    {
      if (tmp->fd_player == player->fd_associate)
	{
	}
      tmp = tmp->next;
    }
  player->stacklast = NULL;
}

static void	remove_cmd_stack(t_env *e)
{
  t_stack	*tmp;
  t_players	*player;

  tmp = e->execution;
  player = get_player_byfd(e, e->execution->fd_player);
  if (player->stacklast == e->execution)
    player->stacklast = NULL;
  e->execution = e->execution->next;
  free(tmp->cmd);
  free(tmp);
}

static void	execute_cmd_stack(t_env *e, t_stack *stack)
{
  int		i;
  t_players	*player;

  player = e->clients;
  while (player && player->fd_associate != stack->fd_player)
    player = player->next;
  i = -1;
  if (player != NULL)
    while (gl_cmds[++i].id != -1)
      {
	if (strncmp(e->execution->cmd, gl_cmds[i].cmd, strlen(gl_cmds[i].cmd)) == 0)
	  {
	    gl_cmds[i].f(e, player);
	    return ;
	  }
      }
}

void			execute_stack(t_env *e)
{
  struct timeval	timestamp;
  t_stack		*tmp;

  gettimeofday(&timestamp, NULL);
  tmp = e->execution;
  while (tmp &&
	 ((tmp->timestamp.tv_sec - timestamp.tv_sec < 0) ||
	  ((tmp->timestamp.tv_sec == timestamp.tv_sec) &&
	   tmp->timestamp.tv_usec - timestamp.tv_usec <= 0)))
    {
      execute_cmd_stack(e, tmp);
      remove_cmd_stack(e);
      tmp = e->execution;
    }
}
