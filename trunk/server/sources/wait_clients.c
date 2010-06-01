/*
** wait_clients.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Fri May  7 10:58:37 2010 amine mouafik
** Last update Tue Jun  1 19:15:06 2010 alban roux
*/

#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

/**/
#define MAX(a,b)	( (a>b)?(a):(b) )
void	alloc_fd(t_network *e,int fd);
#define READ_SIZE	2048
char		*gnl(const int fd, int *index, char *buff);

static void	set_max_fd(t_network *e,int fd)
{
  int		cur;

  cur = fd-1;
  while (!e->fdt[cur])
    cur--;
  e->max_fd_used = cur;
}

void	close_fd(t_network *e,int fd)
{
  free(e->fdt[fd]);
  e->fdt[fd] = 0;
  close(fd);
  if (e->max_fd_used == fd)
    set_max_fd(e,fd);
}

static void	send_buf(__attribute__((unused))t_network *e, int fd, char *buf, int l)
{
  while (l)
    {
      int	tmp;

      tmp = send(fd,buf,l,0);
      if (tmp < 0)
	{
	  fprintf(stderr,"ARRG send on %d: ",fd);
	  perror("");
	  return;
	}
      buf += tmp;
      l -= tmp;
    }
}

void	std_read(t_env *e,int fd)
{
  int	l;
  int	cur;
  char	*buf;
  t_players *tmp;

  buf = xmalloc(READ_SIZE * sizeof(*buf));
  memset(buf, 0, READ_SIZE * sizeof(*buf));
  l = recv(fd, buf, READ_SIZE, 0);
  if (l <= 0)
    close_fd(e->network,fd);
  else
    {
      tmp = e->clients;
      while (tmp && (tmp->fd_associate != fd))
	tmp = tmp->next;
      if (tmp)
	printf("%sI'm client %d\nmy team is %s%s\n", YELLOW, tmp->fd_associate, tmp->team_name, WHITE);
      printf("%sRECU CMD : %s%s\n", YELLOW, buf, WHITE);
    }
  free(buf);
}

void	do_fd(t_env *e)
{
  int	cur;

  cur = 0;
  while (cur < e->network->max_fd_used + 1)
    {
      if (!e->network->fdt[cur])
	{
	  cur++;
	  continue;
	}
      if (FD_ISSET(cur,&e->network->r))
	e->network->fdt[cur]->in.f(e, cur);
      if (FD_ISSET(cur,&e->network->w))
	e->network->fdt[cur]->out.f(e, cur);
      cur++;
    }
}

static void	init_fd_set(t_env *e)
{
  int		cur;

  cur = 0;
  FD_ZERO(&e->network->r);
  FD_ZERO(&e->network->w);
  while (cur < e->network->max_fd_used + 1)
    {
      if (!e->network->fdt[cur])
	{
	  cur++;
	  continue;
	}
      if (e->network->fdt[cur]->type & T_READ)
	FD_SET(cur,&e->network->r);
      if (e->network->fdt[cur]->type & T_WRITE)
	FD_SET(cur,&e->network->w);
      cur++;
    }
}

void	set_max_fd_used(t_network *e, int fd)
{
  e->max_fd_used = MAX(e->max_fd_used, fd);
}

void	create_player_list(t_env *e, int fd, char *t_name, int x, int y)
{
  t_players	*tmp;

  tmp = xmalloc(sizeof(*tmp));
  tmp->fd_associate = fd;
  tmp->team_name = xmalloc(strlen(t_name) * sizeof(*t_name));
  tmp->team_name = strcpy(tmp->team_name, t_name);
  tmp->posx = x;
  tmp->posy = y;
  tmp->next = NULL;
  e->clients = tmp;
}

void	add_player_list(t_env *e, int fd, char *t_name, int x, int y)
{
  t_players	*tmp;
  t_players	*cur;

  cur = e->clients;
  while (cur->next)
    cur = cur->next;
  tmp = xmalloc(sizeof(*tmp));
  tmp->fd_associate = fd;
  tmp->team_name = strdup(t_name);
  tmp->posx = x;
  tmp->posy = y;
  tmp->next = NULL;
  cur->next = tmp;
}

void	add_player(t_env *e, int fd, char *t_name, int x, int y)
{
  if (e->clients == NULL)
    create_player_list(e, fd, t_name, x, y);
  else
    add_player_list(e, fd, t_name, x, y);
}

void	accept_client(t_env *e, int fd)
{
  char	buf[READ_SIZE];
  int	posx;
  int	posy;

  printf("%s'BIENVENUE' envoye a %d%s\n", BLUE, fd, WHITE);
  memset(buf, 0, READ_SIZE * sizeof(*buf));
  write(fd, "BIENVENUE\n", strlen("BIENVENUE\n"));
  read(fd, buf, READ_SIZE);
  buf[strlen(buf) - 1] = '\0';
  printf("%sRecieved : %s from %d%s\n", RED, buf, fd, WHITE);
  posx = rand() % e->params->width;
  posy = rand() % e->params->height;
  add_player(e, fd, buf, posx, posy);
  printf("%s'%d' envoye a %d%s\n", BLUE, e->params->maxclient, fd, WHITE);
  printf("%s'%d %d' envoye a %d%s\n", BLUE, posx, posy, fd, WHITE);
  memset(buf, 0, READ_SIZE * sizeof(*buf));
  sprintf(buf, "%d\n%d %d\n", e->params->maxclient, posx, posy);
  write(fd, buf, strlen(buf));
}

void			new_connection(t_env *e, int fd_conn)
{
  struct sockaddr_in	name;
  socklen_t		namelen;
  int			fd;
  char			addr[4];

  namelen = sizeof(name);
  fd = accept(fd_conn, (struct sockaddr *)&name, &namelen);
  memcpy(&addr, &name.sin_addr.s_addr, sizeof(name.sin_addr.s_addr));
  if (fd < 0)
    {
      perror("ARRG accept");
      exit(1);
    }
  alloc_fd(e->network, fd);
  e->network->fdt[fd]->type |= T_READ;
  e->network->fdt[fd]->in.f = std_read;
  set_max_fd_used(e->network, fd);
  accept_client(e, fd);
}

int	wait_clients(t_env *e)
{
  int	nfds;

  while (42)
    {
      init_fd_set(e);
      nfds = select(e->network->max_fd_used + 1, &e->network->r, &e->network->w, 0, 0);
      if (nfds)
	do_fd(e);
      else
	{
	  perror("ARRG select");
	  exit(1);
	}
    }
  return 0;
}
