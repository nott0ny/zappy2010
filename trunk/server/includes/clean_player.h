/*
** clean_player.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Sun Jun 20 11:41:27 2010 amine mouafik
*/

#ifndef __CLEAN_PLAYER_H__
# define __CLEAN_PLAYER_H__

void	  	close_fd(t_network *network, short fd);
void		remove_player_stack(t_stack *execution, t_players *player);
t_graphics	*get_graphic_byfd(t_env *e, int fd);

#endif
