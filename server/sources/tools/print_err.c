/*
** print_err.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/tools
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 23:40:26 2010 amine mouafik
** Last update Wed May  5 17:35:16 2010 alban roux
*/

#include <stdio.h>
#include "server.h"

int	print_err(char *str)
{
  fprintf(stderr, "%sError: %s%s\n", RED, str, WHITE);
  return (1);
}
