/*
** get_graphic_infos.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Sun Jun 20 11:37:30 2010 amine mouafik
** Last update Sun Jun 20 11:41:16 2010 amine mouafik
*/

#include <stdlib.h>

#include "types.h"

t_graphics	*get_graphic_byfd(t_env *e, int fd)
{
  t_graphics	*current;

  current = e->graphics;
  while (current)
    {
      if (current->fd_associate == fd)
	return (current);
      current = current->next;
    }
  return (NULL);
}
