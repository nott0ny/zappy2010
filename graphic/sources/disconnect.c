/*
** disconnect.c for disconnect in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/sources
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 16:05:56 2010 adrien veau-greiner
** Last update Thu May 13 22:58:17 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "client.h"

int	disconnect(t_client *cl)
{
  if (shutdown(cl->sock, 2) == -1)
    return (error("shutdown()"));
  xclose(cl->sock);
  return (0);
}
