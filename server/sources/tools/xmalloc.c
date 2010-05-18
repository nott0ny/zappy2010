/*
** xmalloc.c for zappy in /u/all/roux_a/cu/rendu/c/zappy/zappy2010/serveur/sources/tools
** 
** Made by alban roux
** Login   <roux_a@epitech.net>
** 
** Started on  Wed May  5 17:33:01 2010 alban roux
** Last update Wed May  5 17:35:11 2010 alban roux
*/

#include <stdlib.h>
#include "server.h"

void	*xmalloc(unsigned int size)
{
  void	*b;

  b = malloc(size);
  if (b == 0)
    {
      print_err("Can't malloc");
      exit(-1);
    }
  return (b);
}
