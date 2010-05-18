/*
** cmd_bct.c for cmd_bct in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 19:32:42 2010 adrien veau-greiner
** Last update Mon May 17 13:35:52 2010 adrien veau-greiner
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "client.h"

int		cmd_bct(char **params, t_graph *fx)
{
  int		i;
  int		x;
  int		y;

  x = atoi(params[1]);
  y = atoi(params[2]);
  fx->map[y][x] = xmalloc(sizeof(fx->map));
  fx->map[y][x]->test = "toto";
  /*for (i = 1; params[i]; i++)
    printf("%s ", params[i]);*/
  printf("linemate %s\n", fx->map[y][x]->test);
  return (0);
}
