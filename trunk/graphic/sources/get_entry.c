/*
** get_entry.c for get_entry in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/sources
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 12:30:39 2010 adrien veau-greiner
** Last update Thu May 13 16:58:11 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#include "client.h"

int	get_port(char *p, int *cl_p)
{
  int	num_p;

  num_p = atoi(p);
  if (num_p > MAX_PORT || num_p <= 0)
    {
      printf("Error: invalid port %s\n", p);
      return (-1);
    }
  *cl_p = num_p;
  return (0);
}

int	get_host(char *h, t_client *cl)
{
  if ((cl->host = gethostbyname(h)) == NULL)
    {
      printf("\033[31mError => %s\n\033[00m", hstrerror(h_errno));
      return (-1);
    }
  return (0);
}

int	get_entry(char **av, t_client *cl)
{
  int	i;
  int	flag;

  i = 0;
  flag = 0;
  while (i < 4)
    {
      if ((strcmp(av[i], "-p") == 0) && av[i + 1])
	{
	  if (get_port(av[i + 1], &cl->port) == -1)
	    return (-1);
	  flag += 1;
	}
      if ((strcmp(av[i], "-h") == 0) && av[i + 1])
	{
	  if (get_host(av[i + 1], cl) == -1)
	    return (-1);
	  flag += 2;
	}
      i++;
    }
  if (flag != 3)
    return (aff_help());
  return (0);
}
