/*
** x.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:32:30 2010 amine mouafik
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "colors.h"

void	*x(void *err, void *res, char *str, char *file, int line)
{
  if (res == err)
    {
      fprintf(stderr, "Error with %s (in %s, line %d): %s\n",
	      str, file, line, strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (res);
}

void	*_x(void *err, void *res, char *str, char *file, int line)
{
  if (res == err)
    fprintf(stderr, "Error with %s (in %s, line %d): %s\n",
	    str, file, line, strerror(errno));
  return (res);
}

int	_xw(char *str)
{
  fprintf(stderr, "%sError: %s%s\n", RED, str, WHITE);
  return (1);
}

void	*xmalloc(int size, char *file, int line)
{
  void	*p;

  if (!(p = malloc(size)))
    {
      fprintf(stderr, "Can't alloc memory() (in %s, line %d) : %s\n",
	      file, line, strerror(errno));
      exit(EXIT_FAILURE);
    }
  memset(p, 0, size);
  return (p);
}

