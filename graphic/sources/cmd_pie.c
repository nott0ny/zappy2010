/*
** cmd_pie.c for cmd_pie in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Wed Jun  9 22:10:30 2010 adrien veau-greiner
** Last update Thu Jun 10 16:02:54 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>

#include "client.h"

int		cmd_pie(char **params, t_client *cl)
{
  t_player	*temp;
  int		pos_x;
  int		pos_y;

  aff_tab(params);
  if (tablen(params) != 3)
    return (0);
  temp = cl->plist;
  pos_x = atoi(params[1]);
  pos_y = atoi(params[2]);
  return (0);
}
