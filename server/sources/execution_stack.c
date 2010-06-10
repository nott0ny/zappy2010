/*
** execution_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Thu Jun 10 19:45:00 2010 amine mouafik
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "server.h"
#include "colors.h"
#include "x.h"

static void	push_cmd_onstack(t_env *e, t_stack *newcmd)
{
  t_stack     	*current;

  current = e->execution;
  if (current == NULL)
    newcmd->next = NULL;
  else
    newcmd->next = current;
  e->execution = newcmd;
}

void			add_cmd_onstack(t_env *e, int fd_player,
					char *cmd, int duration)
{
  float			durationtime;
  struct timeval	timestamp;
  t_stack		*newcmd;

  gettimeofday(&timestamp, NULL);
  newcmd = Xmalloc(sizeof(*newcmd));
  durationtime = (float)duration / (float)e->params->time;
  durationtime = ceil(durationtime);
  timestamp.tv_sec += durationtime;
  newcmd->timestamp = timestamp;
  newcmd->cmd = cmd;
  newcmd->fd_player = fd_player;
  push_cmd_onstack(e, newcmd);
  printf("%s[%d] Received command '%s'.%s\n",
	 CYAN, fd_player, cmd, WHITE);
}

