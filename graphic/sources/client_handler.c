/*
** client_handler.c for client_handler in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 22:44:03 2010 adrien veau-greiner
** Last update Mon Jun 14 14:24:29 2010 adrien veau-greiner
*/

#include <sys/types.h>
#include <sys/select.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "client.h"
#include "graphics.h"

int client_handler(t_client *cl)
{
  while (!cl->ingame)
    {
      init_fd(cl);
      my_select(cl);
      check_fd(cl);
      manage_display(cl, 1);
    }
  return (0);
}

