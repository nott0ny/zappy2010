/*
** add_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Sun Jun 20 10:12:08 2010 amine mouafik
*/

#include <sys/time.h>
#include <stdlib.h>
#include <math.h>

#include "types.h"
#include "utils.h"
#include "add_stack.h"

static void	add_as_first(t_env *e, t_stack *newcmd)
{
  newcmd->next = e->execution;
  e->execution = newcmd;
}

static void	add_as_sorted(t_stack *current, t_stack *newcmd)
{
  newcmd->next = current->next;
  current->next = newcmd;
}

static void	push_sorted_onstack(t_env *e, t_stack *newcmd)
{
  int		i;
  t_stack     	*cur;

  i = -1;
  cur = e->execution;
  if (e->execution == NULL)
    add_as_first(e, newcmd);
  else
    {
      while (++i != -1 && cur->next &&
	     ((cur->next->timestamp.tv_sec - newcmd->timestamp.tv_sec < 0) ||
	      ((cur->next->timestamp.tv_sec == newcmd->timestamp.tv_sec) &&
	       cur->next->timestamp.tv_usec - newcmd->timestamp.tv_usec <= 0)))
	cur = cur->next;
      if (i == 0 && (((cur->timestamp.tv_sec - newcmd->timestamp.tv_sec > 0)) ||
		     ((cur->timestamp.tv_sec == newcmd->timestamp.tv_sec) &&
		      cur->timestamp.tv_usec - newcmd->timestamp.tv_usec >= 0)))
	add_as_first(e, newcmd);
      else
	add_as_sorted(cur, newcmd);
    }
}

void			add_stack_healthcare(t_env *e, t_players *player,
					     char *cmd, ushort duration)
{
  float			durationtime;
  struct timeval	timestamp;
  t_stack		*newcmd;

  gettimeofday(&timestamp, NULL);
  durationtime = (float)duration / (float)e->params->time;
  timestamp.tv_sec += floor(durationtime);
  timestamp.tv_usec += (int)(durationtime - (float)floor(durationtime)) * USEC;
  newcmd = Xmalloc(sizeof(*newcmd));
  newcmd->timestamp = timestamp;
  newcmd->cmd = cmd;
  newcmd->fd_player = player->fd_associate;
  push_sorted_onstack(e, newcmd);
}

void			add_stack(t_env *e, t_players *player,
				char *cmd, ushort duration)
{
  float			durationt;
  struct timeval	timestamp;
  t_stack		*newcmd;

  player->stacksize++;
  if (player->stacksize <= 10)
    {
      if (player->stacklast)
	timestamp = player->stacklast->timestamp;
      else
	gettimeofday(&timestamp, NULL);
      durationt = (float)duration / (float)e->params->time;
      timestamp.tv_sec += floor(durationt);
      timestamp.tv_usec += (int)(durationt - (float)floor(durationt)) * USEC;
      newcmd = Xmalloc(sizeof(*newcmd));
      newcmd->timestamp = timestamp;
      newcmd->cmd = cmd;
      newcmd->fd_player = player->fd_associate;
      push_sorted_onstack(e, newcmd);
      player->stacklast = newcmd;
    }
  else
    player->stacksize--;
}
