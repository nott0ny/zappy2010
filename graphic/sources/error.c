/*
** error.c for error in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/sources
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 15:21:28 2010 adrien veau-greiner
** Last update Thu May 13 15:50:33 2010 adrien veau-greiner
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	error(char *from)
{
  if (fprintf(stderr, "Error from %s: \033[31m%s\n\033[00m",
	      from, strerror(errno)) == -1)
    {
      printf("%s", strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (-1);
}


char	*nerror(char *from)
{
  if (fprintf(stderr, "Error from %s: \033[31m%s\n\033[00m",
	      from, strerror(errno)) == -1)
    exit(EXIT_FAILURE);
  return (NULL);
}
