/*
** aff.c for aff.c in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/sources
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 13:18:31 2010 adrien veau-greiner
** Last update Thu May 13 22:40:19 2010 adrien veau-greiner
*/

#include <stdio.h>

#include "client.h"

void	aff_start()
{
  printf("%s \n%s\n\n", CLEAN_SCREEN, BANNER);
}

int	aff_help(void)
{
  printf("\033[31mUsage: ./client-fx [-p port] [-h host]\033[00m\n");
  return (-1);
}
