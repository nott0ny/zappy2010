/*
** graphics.h for graphics in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:22:28 2010 adrien veau-greiner
** Last update Wed Jun  9 12:14:41 2010 adrien veau-greiner
*/

#ifndef __GRAPHICS_H__
# define __GRAPHICS_H__

# include "player.h"

/* ------ MACRO ------*/

/* --- Structures --- */

typedef struct	s_case
{
  int		nb_food;
  int		nb_linemate;
  int		nb_deraunere;
  int		nb_sibur;
  int		nb_mandiane;
  int		nb_phiras;
  int		nb_thystane;
  int		nb_player;
  char		*team_name;
  int		status;
}		t_case;

typedef struct	s_graphics
{
  t_case	***map;
  int		size;
  int		size_x;
  int		size_y;
}		t_graph;

#endif
