/*
** global.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun  7 21:48:51 2010 alban roux
*/

#ifndef __GLOBAL_H__
# define __GLOBAL_H__

t_cmds	gl_cmds[] = {
  {0, "avance\n", go_forward, 7},
  {1, "droite\n", rotate_right, 7},
  {2, "gauche\n" , rotate_left, 7},
  {3, "voir\n" , explore, 7},
  {4, "inventaire\n" , list_inventory, 1},
  {5, "prend" , take_object, 7},
  {6, "pose" , drop_object, 7},
  {7, "expulse\n" , expulse, 7},
  {8, "broatcast\n" , broadcast, 7},
  {9, "incantation\n" , incantation, 300},
  {10, "fork\n" , player_fork, 42},
  {-1, 0, 0, 0}
};

#endif
