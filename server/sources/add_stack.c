/*
** add_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Mon Jun 14 14:53:19 2010 amine mouafik
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
  t_stack     	*current;

  i = -1;
  current = e->execution;
  if (e->execution == NULL)
    add_as_first(e, newcmd);
  else
    {
      while (++i != -1 && current->next &&
	     ((current->next->timestamp.tv_sec - newcmd->timestamp.tv_sec < 0) ||
	      ((current->next->timestamp.tv_sec == newcmd->timestamp.tv_sec) &&
	       current->next->timestamp.tv_usec - newcmd->timestamp.tv_usec <= 0)))
	current = current->next;
      if (i == 0 && (((current->timestamp.tv_sec - newcmd->timestamp.tv_sec > 0)) ||
	  ((current->timestamp.tv_sec == newcmd->timestamp.tv_sec) &&
	   current->timestamp.tv_usec - newcmd->timestamp.tv_usec >= 0)))
	add_as_first(e, newcmd);
      else
	add_as_sorted(current, newcmd);
    }
}

void			add_stack(t_env *e, int fd_player,
				char *cmd, int duration)
{
  float			durationtime;
  struct timeval	timestamp;
  t_stack		*newcmd;

  gettimeofday(&timestamp, NULL);
  newcmd = Xmalloc(sizeof(*newcmd));
  durationtime = (float)duration / (float)e->params->time;
  timestamp.tv_sec += floor(durationtime);
  timestamp.tv_usec += (int)(durationtime - (float)floor(durationtime)) * USEC;
  newcmd->timestamp = timestamp;
  newcmd->cmd = cmd;
  newcmd->fd_player = fd_player;
  push_sorted_onstack(e, newcmd);
}

