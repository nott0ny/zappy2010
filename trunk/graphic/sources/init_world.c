/*
** init_world.c for init_world in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 17:55:00 2010 adrien veau-greiner
** Last update Fri May 14 18:26:34 2010 adrien veau-greiner
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "client.h"
#include "graphics.h"

int		init_world(t_client *cl, t_graph *fx)
{
  char		*cmd;

  cmd = receive_command(cl->sock);
  if (strcmp(cmd, "BIENVENUE") == 0)
    return (receive_start_conf(cl, fx));
  else
    {
      printf("Error: \033[31mNot receive %s\n", NAME);
      return (-1);
    }
  return (0);
}
