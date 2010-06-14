/*
** destruct_cl.c for destruct_cl in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Mon Jun 14 14:24:50 2010 adrien veau-greiner
** Last update Mon Jun 14 14:25:59 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <unistd.h>

#include "client.h"

void	destruct_cl(t_client *cl)
{
  free(cl);
  return ;
}
