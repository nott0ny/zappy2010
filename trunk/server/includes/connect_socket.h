/*
** connect_socket.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __CONNECT_SOCKET_H__
# define __CONNECT_SOCKET_H__

# define STD_BACKLOG	5
# ifndef SO_NOSIGPIPE
#  define SO_NOSIGPIPE 0
# endif

void	alloc_fd(t_network *network, ushort fd);
void   	new_connection(t_env *e, int fd_conn);

#endif
