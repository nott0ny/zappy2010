/*
** cmd_msz.c for cmd_msz in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:36:07 2010 adrien veau-greiner
** Last update Wed Jun  9 01:34:01 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>

#include "client.h"
#include "graphics.h"

int	cmd_msz(__attribute__((unused))char **params,
		__attribute__((unused))t_client *cl)
{
  int i;

  if (tablen(params) != 3)
    return (0);
  cl->fx->x = atoi(params[1]);
  cl->fx->y = atoi(params[2]);
  cl->fx->size = cl->fx->y * cl->fx->x;
  cl->fx->map = xmalloc(sizeof(t_case***) * cl->fx->x);
  i = 0;
  while (i <= cl->fx->x)
    cl->fx->map[i++] = xmalloc(sizeof(t_case**) * cl->fx->y);
  printf("size %d %d\n", cl->fx->x, cl->fx->y);
  return (0);
}
