/*
** init.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 23:41:30 2010 amine mouafik
** Last update Fri May  7 10:11:19 2010 amine mouafik
*/

#include <stdlib.h>
#include "server.h"

int	init_params(t_params *params)
{
  params->port = DEFAULT_PORT;
  params->width = DEFAULT_WIDTH;
  params->height = DEFAULT_HEIGHT;
  params->teams = NULL;
  params->maxclient = DEFAULT_CLIENT;
  params->time = DEFAULT_TIME;
  return (0);
}
