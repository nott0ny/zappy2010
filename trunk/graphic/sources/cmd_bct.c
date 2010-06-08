/*
** cmd_bct.c for cmd_bct in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 19:32:42 2010 adrien veau-greiner
** Last update Wed Jun  9 01:33:30 2010 adrien veau-greiner
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "client.h"

int		cmd_bct(__attribute__((unused))char **params,
			__attribute__((unused))t_client *cl)
{
  int pos_x;
  int pos_y;

  if (tablen(params) != 10)
    return (0);
  pos_x = atoi(params[1]);
  pos_y = atoi(params[2]);
  cl->fx->map[pos_x][pos_y] = xmalloc(sizeof(t_case)); 
  cl->fx->map[pos_x][pos_y]->status = 1;
  printf("case %d %d\n", pos_x, pos_y);
  return (0);
}
