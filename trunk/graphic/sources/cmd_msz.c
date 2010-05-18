/*
** cmd_msz.c for cmd_msz in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:36:07 2010 adrien veau-greiner
** Last update Fri May 14 19:06:22 2010 adrien veau-greiner
*/

#include <stdlib.h>

#include "client.h"
#include "graphics.h"

int	cmd_msz(char **params, t_graph *fx)
{
  if (tablen(params) != 3)
    return (-1);
  if (!str_isnum(params[1]) || !str_isnum(params[2]))
    return (-1);
  fx->x = atoi(params[1]);
  fx->y = atoi(params[2]);
  return (0);
}
