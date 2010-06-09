/*
** cmd_bct.c for cmd_bct in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 19:32:42 2010 adrien veau-greiner
** Last update Wed Jun  9 19:46:21 2010 adrien veau-greiner
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "client.h"

int		*get_ressource(char **params, int index)
{
  int		i;
  int		j;
  int		*mcase;

  i = 0;
  j = index;
  mcase = xmalloc(sizeof(int*) * 7);
  while (params[j])
    mcase[i] = atoi(params[j++]);
  return (mcase); 
}

int		cmd_bct(char **params, t_client *cl)
{
  int pos_x;
  int pos_y;

  if (tablen(params) != 10)
    return (0);
  pos_x = atoi(params[1]);
  pos_y = atoi(params[2]);
  cl->fx->map[pos_x][pos_y] = xmalloc(sizeof(t_case)); 
  cl->fx->map[pos_x][pos_y]->ress = get_ressource(params, 3); 
  return (0);
}
