/*
** add_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Tue Jun 15 12:06:19 2010 amine mouafik
*/

#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "server.h"
#include "utils.h"

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

void			add_stack(t_env *e, t_players *player,
				char *cmd, ushort duration)
{
  float			durationtime;
  struct timeval	timestamp;
  struct timeval	exist;
  t_stack		*newcmd;

  gettimeofday(&timestamp, NULL);
  durationtime = (float)duration / (float)e->params->time;
  timestamp.tv_sec += floor(durationtime);
  if (player->stacklast)
    exist = player->stacklast->timestamp;
  else
    gettimeofday(&exist, NULL);
  timestamp.tv_sec += (timestamp.tv_sec - exist.tv_sec);
  timestamp.tv_usec += (int)(durationtime - (float)floor(durationtime)) * USEC;
  newcmd = Xmalloc(sizeof(*newcmd));
  newcmd->timestamp = timestamp;
  newcmd->cmd = cmd;
  newcmd->fd_player = player->fd_associate;
  player->stacklast = newcmd;
  push_sorted_onstack(e, newcmd);
}

