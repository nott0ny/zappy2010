/*
** receive_size.c for receive_size in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 19:14:38 2010 adrien veau-greiner
** Last update Fri May 14 19:18:33 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "graphics.h"

int	receive_size(t_client *cl, t_graph *fx)
{
  char	*size;
  char	**params;

  size = receive_command(cl->sock);
  if (strncmp(size, "msz", 3) == 0)
    {
      params = str_to_wordtab(size, ' ');
      if (cmd_msz(params, fx) == -1)
	{
	  free(size);
	  free(params);
	  return (-1);
	}
      free(params);
    }
  else
    {
      printf("error: \033[31mNot receive map size !!!\033[00m\n");
      free(size);
      return (-1);
    }
  printf("Receive map size x: %d y: %d\n", fx->x, fx->y);
  free(size);
  return (0);
}
