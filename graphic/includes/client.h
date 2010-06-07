/*
** client.h for client in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/includes
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 12:33:33 2010 adrien veau-greiner
** Last update Mon Jun  7 20:38:46 2010 adrien veau-greiner
*/

#ifndef __CLIENT_H__
# define __CLIENT_H__

# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <netdb.h>

# include "graphics.h"
# include "player.h"

/* ----- MACRO ----- */

# define MAX_PORT	65535
# define READ_B		512
# define MAXCMD_LEN	256
# define BUFFER         4096
# define PROTO		"IP"
# define NAME		"GRAPHIC\n"
# define CLEAN_SCREEN	"\033[H\033[2J"
# define BANNER		"____________ ZappyFX Tools ____________"


/* --- Structure --- */

typedef struct		s_client {
  int			port;
  int			sock;
  socklen_t		addrlen;
  int                   f_send;
  char                  *cmd;
  char                  *send_buff;
  fd_set                rdfs;
  fd_set                wrfs;
  t_graph               *fx;                
  struct sockaddr_in	sin;
  struct protoent	*proto;
  struct hostent	*host;
}		t_client;

/* ----------------- */

/* aff.c */
void	aff_start(void);
int	aff_help(void);

/* check_command.c */
int	check_command(t_client *cl);

/* check_fd.c */
void  check_fd(t_client *cl);

/* client_handler.c */
int	client_handler(t_client *cl);

/* connect_server.c */
int	connect_server(t_client *cl);

/* cmd_*.c */
int	cmd_bct(char **param, t_client *cl);
int	cmd_tna(char **param, t_client *cl);
int	cmd_msz(char **param, t_client *cl);
int	cmd_sgt(char **param, t_client *cl);
int     cmd_init(char **params, t_client *cl);

/* disconnect.c */
int	disconnect(t_client *cl);

/* error.c */
int	error(char *from);
char	*nerror(char *from);

/* get_entry.c */
int	get_entry(char **av, t_client *cl);

/* init_cl.c */
void    init_cl(t_client *cl);

/* init_client.c */
int    init_client(t_client *cl);

/* init_fd.c */
void   init_fd(t_client *cl);

/* init_graph.c */
void	init_graph(t_graph *fx);

/* init_world */
int	init_world(t_client *cl, t_graph *fx);

/* my_select */
void    my_select(t_client *cl);

/* receive_command.c */
char	*gnl(const int fd, int *index, char *buff);
char	*getnl(char *str, int *index, const int fd);
char	*receive_command(int sock);

/* receive_map.c */
int	receive_map(t_client *cl, t_graph *fx);

/* receive_size.c */
int	receive_size(t_client *cl, t_graph *fx);

/* receive_start_conf.c */
int	receive_start_conf(t_client *cl, t_graph *fx);

/* receive_time_unitu.c */
int	receive_time_unity(t_client *cl, t_graph *fx);

/* start_client.c */
int	start_client(t_client *cl);

/* str_to_wortab.c */
char	**str_to_wordtab(char *str, char dif);

/* utils.c */
char	*my_strcat(char *str1, char *str2);
int	str_isnum(char *str);
int	tablen(char **tab);
void aff_tab(char **tab);

/* xfunctions.c */
void	xclose(int fd);
int	xread(int fd, char *buf, int count);
void	*xmemset(char *addr, char c, size_t size);
void	*xmalloc(size_t size);
int	xerror(char *from);

#endif
