/*
** check_command.c for check_command in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:06:34 2010 adrien veau-greiner
** Last update Fri May 14 19:33:38 2010 adrien veau-greiner
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "client.h"
#include "command.h"

int		cmd_tna(char **params, t_graph *fx)
{
  int		i;

  fx = fx;
  for (i = 0; params[i]; i++)
    printf("%s ", params[i]);
  printf("\n");
  return (0);
}

int		check_command(char *cmd, t_graph *fx)
{
  char		**params;
  int		i;

  i = 0;
  params = str_to_wordtab(cmd, ' ');
  while (cmd_tab[i].cmd_name != 0)
    {
      if (strcmp(params[0], cmd_tab[i].cmd_name) == 0)
	return (cmd_tab[i].f(params, fx));
      i++;
    }
  printf("command not found\n");
  free(params);
  return (0);
}
