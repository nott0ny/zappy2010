/*
** init_fx.c for init_fx in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:46:54 2010 adrien veau-greiner
** Last update Fri May 14 00:10:38 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "graphics.h"

int	init_fx(t_client *cl, t_graph *fx)
{
  char	*size;

  fx = fx;
  write(cl->sock, NAME, strlen(NAME) + 1);
  size = receive_command(cl->sock);
  if (strncmp(size, "msz", 3) == 0)
    printf("%s\n", size);
  free(size);
  size = receive_command(cl->sock);
  if (strncmp(size, "sgt", 3) == 0)
    printf("%s\n", size);
  return (0);
}
