/*
** client_handler.c for client_handler in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 22:44:03 2010 adrien veau-greiner
** Last update Fri May 14 18:03:42 2010 adrien veau-greiner
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "client.h"
#include "graphics.h"

int		client_handler(t_client *cl)
{
  t_graph	fx;
  char		*cmd;

  init_graph(&fx);
  if (init_world(cl, &fx) == -1)
    return (-1);
  while (42)
    {
      if ((cmd = receive_command(cl->sock)) == NULL)
	{
	  printf("exit\n");
	  return (disconnect(cl));
	}
      if (check_command(cmd, &fx) == -1)
	return (disconnect(cl));
      free(cmd);
    }
  return (0);
}
