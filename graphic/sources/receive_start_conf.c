/*
** init_fx.c for init_fx in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:46:54 2010 adrien veau-greiner
** Last update Mon May 17 13:44:26 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "graphics.h"

void	init_map(int size, t_graph *fx)
{
  int	i;

  fx->map = xmalloc(sizeof(**fx->map) * (fx->y + 1));
  i = 0;
  while (i < size)
    {
      fx->map[i] = xmalloc(sizeof(**fx->map) * fx->x);
      i++;
    }
  fx->map[i] = NULL;
}

int	receive_start_conf(t_client *cl, t_graph *fx)
{
  write(cl->sock, NAME, strlen(NAME) + 1);
  if (receive_size(cl, fx) == -1)
    return (-1);
  init_map(fx->y, fx);
  if (receive_time_unity(cl, fx) == -1)
    return (-1);
  /*if (receive_map(cl, fx) == -1)
    return (-1);*/
  return (0);
}
