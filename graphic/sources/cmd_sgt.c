/*
** cmd_sgt.c for cmd_sgt in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:58:39 2010 adrien veau-greiner
** Last update Fri May 14 19:06:24 2010 adrien veau-greiner
*/

#include <stdlib.h>

#include "client.h"
#include "graphics.h"

int	cmd_sgt(char **params, t_graph *fx)
{
  if (tablen(params) != 2)
    return (-1);
  if (!str_isnum(params[1]))
    return (-1);
  fx->time_u = atoi(params[1]);
  return (0);
}
