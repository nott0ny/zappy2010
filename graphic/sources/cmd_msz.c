/*
** cmd_msz.c for cmd_msz in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:36:07 2010 adrien veau-greiner
** Last update Wed Jun  9 14:12:22 2010 adrien veau-greiner
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
  cl->fx->size_x = atoi(params[1]);
  cl->fx->size_y = atoi(params[2]);
  cl->fx->size = cl->fx->size_y * cl->fx->size_x;
  cl->fx->map = xmalloc(sizeof(t_case***) * cl->fx->size_x);
  i = 0;
  while (i <= cl->fx->size_x)
    cl->fx->map[i++] = xmalloc(sizeof(t_case**) * cl->fx->size_y);
  printf("WorldX(%d) WorldY(%d)\n", cl->fx->size_x, cl->fx->size_y);
  return (0);
}
