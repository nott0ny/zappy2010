/*
** start_client.c for start_client in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/sources
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 15:47:44 2010 adrien veau-greiner
** Last update Mon Jun 14 14:26:27 2010 adrien veau-greiner
*/

#include "client.h"

int	start_client(t_client *cl)
{
  aff_start();
  if (connect_server(cl) == -1)
    return (-1);
  if (init_display(cl))
    return (-1);
  if (client_handler(cl) == -1)
    return (-1);
  disconnect(cl);
  destruct_cl(cl);
  SDL_Quit();
  return (0);
}
