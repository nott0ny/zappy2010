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
      printf("Id Commande (%s) FD Player (%d)\n", 
	     stack->cmd, stack->fd_player);
      stack = stack->next;
    }
  printf("--- Stack End ---\n");
}

static void	push_sorted_onstack(t_env *e, t_stack *newcmd)
{
  t_stack     	*current;
  t_stack	*prev = NULL;
  int	i = 0;

  current = e->execution;
  if (current == NULL)
    {
      newcmd->next = NULL;
      e->execution = newcmd;
      return ;
    }
  while (current->next && ((int)current->timestamp.tv_sec - (int)newcmd->timestamp.tv_sec) < 0)
    {
      printf ("[%d] %d timestamp dif\n",i++, (int)current->timestamp.tv_sec - (int)newcmd->timestamp.tv_sec);
      prev = current;
      current = current->next;
    }
  printf ("[%d] %d timestamp dif\n",i++, (int)current->timestamp.tv_sec - (int)newcmd->timestamp.tv_sec);
  /*  if (current->next == NULL)
    {
      current->next = newcmd;
      newcmd->next = NULL;
    }
    else*/
  if (prev == NULL)
    {
      newcmd->next = current;
      e->execution = newcmd;
    }
  else
    {
      newcmd->next = prev->next;
      prev->next = newcmd;
    }
}

void			add_cmd_onstack(t_env *e, int fd_player, char *cmd, int duration)
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
  push_sorted_onstack(e, newcmd);
  display_stack(e->execution);
}

