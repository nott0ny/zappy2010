/*
** load_network.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:55:53 2010 amine mouafik
** Last update Mon May 31 15:28:18 2010 alban roux
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

#include "server.h"

/* */
#define STD_BACKLOG	5
void			new_connection(t_network *e,int fd_conn);
void	set_max_fd_used(t_network *e, int fd);

t_network	*init_network(t_params *params)
{
  t_network	*network;

  network = xmalloc(sizeof(*network));
  memset(network, 0, sizeof(*network));
  network->port = params->port;
  return (network);
}

static void	search_max_fd(t_network *e)
{
  struct rlimit	rlp;

  getrlimit(RLIMIT_NOFILE,&rlp);
  if (e->op_flags & OP_U)
    {
      rlp.rlim_cur = rlp.rlim_max;
      if ( (setrlimit(RLIMIT_NOFILE,(struct rlimit *)&rlp)) < 0)
	perror("ARRG setrlimit");
    }
  getrlimit(RLIMIT_NOFILE,&rlp);
  e->max_fd = rlp.rlim_cur;
  if (e->op_flags & OP_V)
    fprintf(stderr,"[verb: max fd = %d]\n",(int)rlp.rlim_cur);
}

static void	alloc_fdt(t_network *e)
{
  e->fdt = xmalloc(e->max_fd * sizeof(**e->fdt));
  memset(e->fdt, 0, e->max_fd * sizeof(**e->fdt));
}

void	init_fdt(t_network *e)
{
  search_max_fd(e);
  alloc_fdt(e);
}

static int		create_bind_socket(int port)
{
  int			fd;
  int			dum;
  struct sockaddr_in	host;

  fd = socket(PF_INET,SOCK_STREAM,0);
  if (fd < 0)
    {
      perror("ARRG socket");
      exit(1);
    }
  dum = 1;
  setsockopt(fd,SOL_SOCKET,SO_REUSEPORT,&dum,sizeof(dum));
  host.sin_family = PF_INET;
  host.sin_port = htons(port);
  host.sin_addr.s_addr = htonl(INADDR_ANY);
  if ( bind(fd,(struct sockaddr *)&host,sizeof(host)) < 0)
    {
      perror("ARRG bind");
      exit(1);
    }
  listen(fd,STD_BACKLOG);
  return (fd);
}

void	alloc_fd(t_network *e,int fd)
{
  e->fdt[fd] = xmalloc(sizeof(*e->fdt[fd]));
  memset(e->fdt[fd], 0, sizeof(*e->fdt[fd]));
}

void	init_connect_socket(t_network *e)
{
  int	fd;

  fd = create_bind_socket(e->port);
  alloc_fd(e,fd);
  e->fdt[fd]->type |= (T_CONN|T_READ);
  e->fdt[fd]->in.f = new_connection;
  set_max_fd_used(e, fd);
}

t_network	*load_network(t_params *params)
{
  t_network	*network;

  network = init_network(params);
  init_fdt(network);
  init_connect_socket(network);
  return (network);
}
