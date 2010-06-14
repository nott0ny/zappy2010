/*
** graphics.h for graphics in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:22:28 2010 adrien veau-greiner
** Last update Mon Jun 14 17:22:42 2010 adrien veau-greiner
*/

#ifndef __GRAPHICS_H__
# define __GRAPHICS_H__

# include <SDL/SDL.h>

/* ------ MACRO ------*/

# define MAX_PLAYER	1024
# define INIT_WIN_TITLE	"Loading - Zappy FX"
# define GAME_WIN_TITLE	"InGame - Zappy FX"
# define WINDOW_BPP	16
# define INIT_WINDOW_X	640
# define INIT_WINDOW_Y	400
# define GAME_WINDOW_X  800
# define GAME_WINDOW_Y	600
# define CASE_H		44
# define CASE_W		85

# define IMG_LOAD	"images/loading_zappy.jpg"
# define IMG_CASE	"images/case.png"
# define IMG_BACK	""

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
  SDL_Surface	event;
  SDL_Surface	*window;
  SDL_Surface	*loading;
  SDL_Surface	*background;
  SDL_Surface	*scase;
  SDL_Rect	*pos;
}		t_ui;

typedef struct	s_graphics
{
  t_case	***map;
  t_ui		*gui;
  int		size;
  int		size_x;
  int		size_y;
}		t_graph;

#endif
