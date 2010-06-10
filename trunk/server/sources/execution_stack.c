/*
** execution_stack.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Thu Jun 10 19:45:00 2010 amine mouafik
*/

#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "server.h"
#include "utils.h"

static void	display_stack(t_stack *execution)
{
  t_stack	*stack;
  int		i;

  i = 0;
  stack = execution;
  printf("--- Stack Begin ---\n");
  while (stack)
    {
      printf("[%d] Timestamp(%d) ", i++, stack->timestamp);
      printf("Id Commande (%s) FD Player (%d)\n", 
	     stack->cmd, stack->fd_player);
      stack = stack->next;
    }
  printf("--- Stack End ---\n");
}

static void	push_cmd_onstack(t_env *e, t_stack *newcmd)
{
  t_stack     	*current;
  int		i;

  if (e->execution == NULL)
    {
      newcmd->next = NULL;
      e->execution = newcmd;
      printf("[debug] timestamp commande %d \n", (int)newcmd->timestamp); 
    }
  else
    {
      i = 0;
      current = e->execution;
      while (current->next && (current->next->timestamp - newcmd->timestamp < 0))
	{
	  i++;
	  current = current->next;
	}
      if (i == 0)
	{
	  if ((current->timestamp - newcmd->timestamp) > 0)
	    {
	      newcmd->next = e->execution;
	      e->execution = newcmd;
	    }
	  else
	    {
	      newcmd->next = current->next;
	      current->next = newcmd;
	    }
	}
      else
	{
	  newcmd->next = current->next;
	  current->next = newcmd;
	}
      printf("[debug] timestamp commande %d, timestamp prev %d // res %d \n", (int)newcmd->timestamp,(int)current->timestamp, (int)(- newcmd->timestamp + current->timestamp));
    }
}

void			add_cmd_onstack(t_env *e, int fd_player,
					char *cmd, int duration)
{
  float			durationtime;
  int			timestamp;
  t_stack		*newcmd;

  timestamp = (int)time(NULL);
  newcmd = Xmalloc(sizeof(*newcmd));
  durationtime = (float)duration / (float)e->params->time;
  durationtime = ceil(durationtime);
  timestamp += durationtime;
  newcmd->timestamp = timestamp;
  newcmd->cmd = cmd;
  newcmd->fd_player = fd_player;
  push_cmd_onstack(e, newcmd);
  display_stack(e->execution);
  printf("%s[%d] Received command '%s'.%s\n",
	 CYAN, fd_player, cmd, WHITE);
}

