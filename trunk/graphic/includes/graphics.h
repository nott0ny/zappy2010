/*
** graphics.h for graphics in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:22:28 2010 adrien veau-greiner
** Last update Mon Jun 14 11:22:45 2010 adrien veau-greiner
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
  int           eggs_id;
  int		status;
}		t_case;

typedef struct	s_ui
{
  SDL_Surface	*window;
}

typedef struct	s_graphics
{
  t_case	***map;
  t_ui		*gui;
  int		size;
  int		size_x;
  int		size_y;
}		t_graph;

#endif
