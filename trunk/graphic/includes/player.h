/*
** player.h for player in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Fri May 14 14:31:47 2010 adrien veau-greiner
** Last update Fri May 14 14:43:01 2010 adrien veau-greiner
*/

#ifndef __PLAYER_H__
# define __PLAYER_H__

/* ------ MACRO ------ */

/* ---- Strucutre ---- */

typedef struct	s_resource
{
  int		nb_food;
  int		nb_linemate;
  int		nb_deraunere;
  int		nb_sibur;
  int		nb_mandiane;
  int		nb_phiras;
  int		nb_thystane;
}		t_rsrc;

typedef  struct	s_player
{
  char		*team_name;
  int		id;
  int		pos_x;
  int		pos_y;
  int		life;
  int		level;
  int		status;
  t_rsrc	*inventory;
}		t_player;

#endif
