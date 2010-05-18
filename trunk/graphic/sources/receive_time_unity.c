/*
** receive_time_unity.c for receive_time_unity in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 19:13:32 2010 adrien veau-greiner
** Last update Fri May 14 19:18:52 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "graphics.h"

int	receive_time_unity(t_client *cl, t_graph *fx)
{
  char	*time_u;
  char	**params;

  time_u = receive_command(cl->sock);
  if (strncmp(time_u, "sgt", 3) == 0)
    {
      params = str_to_wordtab(time_u, ' ');
      if (cmd_sgt(params, fx) == -1)
	{
	  free(time_u);
	  free(params);
	  return (-1);
	}
      free(params);
    }
  else
    {
      printf("error: \033[31mNot receive time unity !!!\033[00m\n");
      free(time_u);
      return (-1);
    }
  printf("Receive time unity: %d\n", fx->time_u);
  free(time_u);
  return (0);
}
