/*
** connect_socket.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:13:39 2010 amine mouafik
** Last update Mon Jun  7 15:50:15 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "server.h"
#include "utils.h"
#include "connect_socket.h"

static ushort		create_bind_socket(int port)
{
  struct sockaddr_in	host;
  int       		dum;
  ushort       		fd;

  fd = (int)X(-1, socket(PF_INET,SOCK_STREAM,0), "socket");
  dum = 1;
  X(-1, setsockopt(fd, IPPROTO_IP, IP_TOS, &dum, sizeof(dum)), "setsockopt");
  host.sin_family = PF_INET;
  host.sin_port = htons(port);
  host.sin_addr.s_addr = htonl(INADDR_ANY);
  X(-1, bind(fd, (struct sockaddr *)&host, sizeof(host)), "bind");
  X(-1, listen(fd,STD_BACKLOG), "listen");
  return (fd);
}

ushort		init_connect_socket(t_network *network)
{
  ushort	fd;

  fd = create_bind_socket(network->port);
  alloc_fd(network, fd);
  network->fdt[fd]->type |= (T_CONN | T_READ);
  network->fdt[fd]->in.f = new_connection;
  network->max_fd_used = MAX(network->max_fd_used, fd);
  return (0);
}
