/*
** receive_map.c for receive_map in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 19:15:03 2010 adrien veau-greiner
** Last update Mon May 17 13:14:16 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "graphics.h"

int	receive_map(t_client *cl, t_graph *fx)
{
  char	**params;
  char	*sqr;
  int	i;
  int	size;

  i = 0;
  size = (fx->x * fx->y);
  while (i < size)
    {
      sqr = receive_command(cl->sock);
      if (!strcmp(sqr, "bct"))
	{
	  free(sqr);
	  return (-1);
	}
      params = str_to_wordtab(sqr, ' ');
      cmd_bct(params, fx);
      free(params);
      free(sqr);
      i++;
    }
  printf("nb_cases: %d\n", i);
  return (0);
}
