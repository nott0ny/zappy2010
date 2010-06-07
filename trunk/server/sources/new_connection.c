/*
** new_connection.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 15:03:47 2010 amine mouafik
** Last update Mon Jun  7 16:03:32 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"
#include "colors.h"
#include "x.h"

static void	accept_client(t_env *e, int fd)
{
  char		buf[READ_SIZE];
  int		posx;
  int		posy;

  printf("%s'BIENVENUE' envoye a %d%s\n", BLUE, fd, WHITE);
  X(NULL, memset(buf, 0, READ_SIZE * sizeof(*buf)), "memset");
  X((void *)-1, (void *)write(fd, "BIENVENUE\n", strlen("BIENVENUE\n")),
    "write");
  X((void *)-1, (void *)read(fd, buf, READ_SIZE), "read");
  buf[strlen(buf) - 1] = '\0';
  printf("%sRecieved : %s from %d%s\n", RED, buf, fd, WHITE);
  posx = rand() % e->params->width;
  posy = rand() % e->params->height;
  add_player(e, fd, buf, posx, posy);
  printf("%s'%d' envoye a %d%s\n", BLUE, e->params->maxclient, fd, WHITE);
  printf("%s'%d %d' envoye a %d%s\n", BLUE, posx, posy, fd, WHITE);
  X(NULL, memset(buf, 0, READ_SIZE * sizeof(*buf)), "memset");
  sprintf(buf, "%d\n%d %d\n", e->params->maxclient, posx, posy);
  X((void *)-1, (void *)write(fd, buf, strlen(buf)), "write");
}

void			new_connection(t_env *e, int fd_conn)
{
  struct sockaddr_in	name;
  socklen_t		namelen;
  int			fd;
  char			addr[4];

  namelen = sizeof(name);
  fd = (int)X((void *)-1, 
	      (void *)accept(fd_conn, (struct sockaddr *)&name,&namelen),
	      "accept");
  X(NULL, memcpy(&addr, &name.sin_addr.s_addr, sizeof(name.sin_addr.s_addr)),
    "memcpy");
  alloc_fd(e->network, fd);
  e->network->fdt[fd]->type |= T_READ;
  e->network->fdt[fd]->in.f = stdread;
  e->network->max_fd_used = MAX(e->network->max_fd_used, fd);
  accept_client(e, fd);
}
