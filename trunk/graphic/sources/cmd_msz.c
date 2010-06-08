/*
** cmd_msz.c for cmd_msz in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:36:07 2010 adrien veau-greiner
** Last update Tue Jun  8 18:01:17 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>

#include "client.h"
#include "graphics.h"

int	cmd_msz(__attribute__((unused))char **params,
		__attribute__((unused))t_client *cl)
{
  printf("cmd_msz => ");
  aff_tab(params);
  return (0);
}
