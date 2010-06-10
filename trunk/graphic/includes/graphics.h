/*
** graphics.h for graphics in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:22:28 2010 adrien veau-greiner
** Last update Thu Jun 10 12:16:16 2010 adrien veau-greiner
*/

#ifndef __GRAPHICS_H__
# define __GRAPHICS_H__

/* ------ MACRO ------*/

# define MAX_PLAYER 1024

/* --- Structures --- */

typedef struct	s_case
{
  char		*ress;
  int		players_id[MAX_PLAYER];
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
