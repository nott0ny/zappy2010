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
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

#include "types.h"
#include "fdts.h"
#include "utils.h"
#include "connect_socket.h"

static short		create_bind_socket(int port)
{
  struct sockaddr_in	host;
  static int           	dum = 4;
  struct protoent       *p;
  short       		fd;

  p = (struct protoent *)X(NULL, getprotobyname("tcp"), "getprotobyname");
  fd = (int)X(-1, socket(PF_INET, SOCK_STREAM, p->p_proto), "socket");
  dum = SO_NOSIGPIPE ? (int)X(-1, setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE,
					     &dum, sizeof(dum)),
			      "setsockopt") : 0;
  host.sin_family = PF_INET;
  host.sin_port = htons(port);
  host.sin_addr.s_addr = htonl(INADDR_ANY);
  X(-1, bind(fd, (struct sockaddr *)&host, sizeof(host)), "bind");
  X(-1, listen(fd, STD_BACKLOG), "listen");
  return (fd);
}

ushort		init_connect_socket(t_network *network, t_params *params)
{
  short		fd;

  fd = create_bind_socket(params->port);
  network->fdt[fd] = Xmalloc(sizeof(*network->fdt[fd]));
  network->fdt[fd]->type |= (T_CONN | T_READ);
  network->fdt[fd]->in.f = new_connection;
  network->max_fd_used = MAX(network->max_fd_used, fd);
  return (0);
}
