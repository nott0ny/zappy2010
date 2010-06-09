/*
** cmd_sgt.c for cmd_sgt in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:58:39 2010 adrien veau-greiner
** Last update Wed Jun  9 14:12:54 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>

#include "client.h"
#include "graphics.h"

int	cmd_sgt(char **params, t_client *cl)
{
  if (tablen(params) != 2)
    return (0);
  cl->time_u = atoi(params[1]);
  printf("time unity : %d\n", cl->time_u);
  return (0);
}
