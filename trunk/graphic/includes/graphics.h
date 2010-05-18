/*
** graphics.h for graphics in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:22:28 2010 adrien veau-greiner
** Last update Mon May 17 13:24:23 2010 adrien veau-greiner
*/

#ifndef __GRAPHICS_H__
# define __GRAPHICS_H__

# include "player.h"

/* ------ MACRO ------*/

/* --- Structures --- */

typedef struct	s_case
{
  t_player	*nb_player;
  t_rsrc	*resource;
  int		status;
  char		*test;
}		t_case;

typedef struct	s_graphics
{
  t_case	***map;
  int		size;
  int		x;
  int		y;
  int		time_u;
}		t_graph;

#endif
