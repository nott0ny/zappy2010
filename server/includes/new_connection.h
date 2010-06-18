/*
** new_connection.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __NEW_CONNECTION_H__
# define __NEW_CONNECTION_H__

void   	stdread(t_env *e, int fd);
void   	stdwrite(t_env *e, int fd);
void	alloc_fd(t_network *network, ushort fd);
void	add_player(t_env *e, ushort fd);

#endif
