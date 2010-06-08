/*
** cmd_sgt.c for cmd_sgt in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 18:58:39 2010 adrien veau-greiner
** Last update Tue Jun  8 18:01:19 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <stdio.h>

#include "client.h"
#include "graphics.h"

int	cmd_sgt(__attribute__((unused))char **params,
		__attribute__((unused))t_client *cl)
{
  printf("cmd_sgt => ");
  aff_tab(params);
  return (0);
}
