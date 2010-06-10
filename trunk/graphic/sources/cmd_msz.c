/*
** cmd_msz.c for cmd_msz in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:36:07 2010 adrien veau-greiner
** Last update Thu Jun 10 13:01:27 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>

#include "client.h"
#include "graphics.h"

int	cmd_msz(char **params, t_client *cl)
{
  int i;
  int j;

  if (tablen(params) != 3)
    return (0);
  cl->fx->size_x = atoi(params[1]);
  cl->fx->size_y = atoi(params[2]);
  cl->fx->size = cl->fx->size_y * cl->fx->size_x;
  cl->fx->map = xmalloc(sizeof(t_case) * cl->fx->size_x);
  i = 0;
  while (i <= cl->fx->size_x)
    {
      j = 0;
      cl->fx->map[i] = xmalloc(sizeof(t_case) * cl->fx->size_y);
      while (j <= cl->fx->size_y)
	{
	  cl->fx->map[i][j] = xmalloc(sizeof(t_case));
	  cl->fx->map[i][j]->ress = NULL;
	  cl->fx->map[i][j]->players_id[0] = 0;
	  cl->fx->map[i][j]->status = -1;
	  j++;
	}
      i++;
    }
  printf("WorldX(%d) WorldY(%d)\n", cl->fx->size_x, cl->fx->size_y);
  return (0);
}
