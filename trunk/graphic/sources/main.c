/*
** main.c for main in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/sources
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 12:28:50 2010 adrien veau-greiner
** Last update Fri May 14 18:27:52 2010 adrien veau-greiner
*/

#include <stdlib.h>

#include "client.h"

int		main(int ac, char **av)
{
  t_client	cl;

  if (ac != 5)
    return (aff_help());
  if (get_entry(av, &cl) == -1)
    return (EXIT_FAILURE);
  if (start_client(&cl) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
