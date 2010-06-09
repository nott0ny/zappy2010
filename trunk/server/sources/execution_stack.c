/*
** execution_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Mon Jun  7 22:05:23 2010 alban roux
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "server.h"
#include "x.h"

static void	display_stack(t_stack *execution)
{
  t_stack	*stack;
  int		i;

  i = 0;
  stack = execution;
  printf("--- Stack Begin ---\n");
  while (stack)
    {
      printf("[%d] Timestamp(%d) ", i++, (int)stack->timestamp.tv_sec);
      printf("Id Commande (%d) FD Player (%d)\n", 
	     stack->id_cmd, stack->fd_player);
      stack = stack->next;
    }
  printf("--- Stack End ---\n");
}

static void	push_sorted_onstack(t_env *e, t_stack *newcmd)
{
  t_stack     	*current;

  current = e->execution;
  if (e->execution == NULL)
    {
      newcmd->next = NULL;
      e->execution = newcmd;
    }
  else
    {
      if (current->next == NULL)
	{
	  if ((int)current->timestamp.tv_sec <= (int)newcmd->timestamp.tv_sec)
	    {
	      current->next = newcmd;
	      newcmd->next = NULL;
	    }
	  else
	    {
	      newcmd->next = current;
	      e->execution = newcmd;
	    }
	  return;
	}
      while (current->next && (int)current->timestamp.tv_sec <= (int)newcmd->timestamp.tv_sec)
	{
	  printf ("%d\n", (int)current->timestamp.tv_sec - (int)newcmd->timestamp.tv_sec);
	  current = current->next;
	}
      printf ("%d\n", (int)current->timestamp.tv_sec - (int)newcmd->timestamp.tv_sec);
      newcmd->next = current->next;
      current->next = newcmd;
    }
}

void			add_cmd_onstack(t_env *e, int fd_player, int id_cmd, int duration)
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
  newcmd->id_cmd = id_cmd;
  newcmd->fd_player = fd_player;
  push_sorted_onstack(e, newcmd);
  display_stack(e->execution);
}

