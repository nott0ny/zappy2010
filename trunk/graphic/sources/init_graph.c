/*
** init_graph.c for init_graph.c in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 14:44:59 2010 adrien veau-greiner
** Last update Mon May 17 13:39:38 2010 adrien veau-greiner
*/

#include <stdlib.h>

#include "client.h"
#include "graphics.h"

void		init_graph(t_graph *fx)
{
  fx = xmalloc(sizeof(*fx));
  fx->map = NULL;
  fx->size = 0;
  fx->x = 0;
  fx->y = 0;
}
