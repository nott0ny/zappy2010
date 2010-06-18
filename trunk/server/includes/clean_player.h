/*
** clean_player.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __CLEAN_PLAYER_H__
# define __CLEAN_PLAYER_H__

void   	close_fd(t_network *network, ushort fd);
void   	remove_player_stack(t_stack *execution, t_players *player);

#endif
