/*
** cmd_bct.c for cmd_bct in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 19:32:42 2010 adrien veau-greiner
** Last update Thu Jun 10 13:02:11 2010 adrien veau-greiner
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "client.h"

char		*get_ressource(char **params, int index)
{
  int		i;
  int		j;
  char		*mcase;

  i = 0;
  j = index;
  mcase = xmalloc(sizeof(char*) * 7);
  while (params[j])
    mcase[i++] = params[j++][0];
  mcase[i] = '\0';
  return (mcase); 
}

int		cmd_bct(char **params, t_client *cl)
{
  int x;
  int y;

  aff_tab(params);
  if (tablen(params) != 10)
    return (0);
  x = atoi(params[1]);
  y = atoi(params[2]);
  cl->fx->map[x][y]->ress = get_ressource(params, 3);
  /* aff_case(x, y, cl);*/
  return (0);
}
