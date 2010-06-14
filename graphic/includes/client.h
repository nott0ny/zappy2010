/*
** client.h for client in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/includes
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 12:33:33 2010 adrien veau-greiner
** Last update Mon Jun 14 16:07:11 2010 adrien veau-greiner
*/

#ifndef __CLIENT_H__
# define __CLIENT_H__

# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <netdb.h>

# include "graphics.h"
# include "ringbuffer.h"

/* ----- MACRO ----- */

# define MAX_PORT	65535
# define MAX_PLAYER	1024
# define MAXCMD_LEN	256
# define CL_INIT	0
# define CL_LOAD	1
# define CL_DISP	2
# define PROTO		"IP"
# define NAME		"GRAPHIC\n"
# define CLEAN_SCREEN	"\033[H\033[2J"
# define BANNER		"____________ ZappyFX Tools ____________"

# define ACT_BRD	0
# define ACT_TAK	1
# define ACT_INC	2
# define ACT_EXP	3
# define ACT_LVL	4
# define ACT_DIE	5
# define ACT_FRK	6
# define ACT_THR        7

# define END_GAME       42

/* --- Structure --- */

typedef struct		s_player
{
  int			id;
  int			o;
  int			action;
  int			status;
  int			level;
  int			pos_x;
  int			pos_y;
  char			*ress;
  char			*team;
  char			*message;
  struct s_player	*next;
}			t_player;

typedef struct		s_client {
  int			port;
  int			sock;
  int                   f_send;
  int		        time_u;
  int			ingame;
  int			status;
  char			*team_name1;
  char			*team_name2;
  char                  cmd[MAXCMD_LEN];
  char                  *send_buff;
  t_player		*plist;
  t_ringbuffer          *read_buff;
  fd_set                rdfs;
  fd_set                wrfs;
  t_graph               *fx;
  socklen_t		addrlen;
  struct sockaddr_in	sin;
  struct protoent	*proto;
  struct hostent	*host;
}		t_client;

/* ----------------- */

/* aff.c */
void	aff_start(void);
void	aff_player(t_client *cl, int id);
void	aff_case(int x, int y, t_client *cl);
int	aff_help(void);

/* check_command.c */
int	check_command(t_client *cl);

/* check_fd.c */
void	check_fd(t_client *cl);

/* client_handler.c */
int	client_handler(t_client *cl);

/* connect_server.c */
int	connect_server(t_client *cl);

/* cmd_*.c */
int     cmd_init(char **params, t_client *cl);
int	cmd_bct(char **param, t_client *cl);
char	*get_ressource(char **params, int index);
int	cmd_tna(char **param, t_client *cl);
int	cmd_msz(char **param, t_client *cl);
int	cmd_sgt(char **param, t_client *cl);
int	cmd_pnw(char **param, t_client *cl);
int	cmd_ppo(char **param, t_client *cl);
int	cmd_plv(char **param, t_client *cl);
int	cmd_pin(char **param, t_client *cl);
int	cmd_pex(char **param, t_client *cl);
int	cmd_pbc(char **param, t_client *cl);
int	cmd_pic(char **param, t_client *cl);
int	cmd_pie(char **param, t_client *cl);
int	cmd_pfk(char **param, t_client *cl);
int	cmd_pdr(char **param, t_client *cl);
int	cmd_pgt(char **param, t_client *cl);
int	cmd_pdi(char **param, t_client *cl);
int	cmd_enw(char **param, t_client *cl);
int	cmd_eht(char **param, t_client *cl);
int	cmd_ebo(char **param, t_client *cl);
int	cmd_edi(char **param, t_client *cl);
int	cmd_seg(char **param, t_client *cl);
int	cmd_smg(char **param, t_client *cl);
int	cmd_suc(char **param, t_client *cl);
int	cmd_sbp(char **param, t_client *cl);

/* destruct_cl.c */
void	destruct_cl(t_client *cl);

/* disconnect.c */
int	disconnect(t_client *cl);

/* error.c */
int	error(char *from);
char	*nerror(char *from);

/* get_entry.c */
int	get_entry(char **av, t_client *cl);

/* get_pos.c */
int	getpos_by_id(int p_id, int opt, t_client *cl);

/* init_cl.c */
void    init_cl(t_client **cl);

/* init_client.c */
int    init_client(t_client *cl);

/* init_display.c */
int	init_display(t_client *cl);

/* init_fd.c */
void   init_fd(t_client *cl);

/* init_graph.c */
void	init_graph(t_graph *fx);

/* init_world */
int	init_world(t_client *cl, t_graph *fx);

/* manage_display.c */
void	manage_display(t_client *cl);

/* manage_players_id.c */
int	player_is_in_case(int x, int y, int p_id, t_client *cl);

/* my_select */
void    my_select(t_client *cl);

/* receive_command.c */
void	receive_command(t_client *cl);

/* receive_map.c */
int	receive_map(t_client *cl, t_graph *fx);

/* receive_size.c */
int	receive_size(t_client *cl, t_graph *fx);

/* receive_start_conf.c */
int	receive_start_conf(t_client *cl, t_graph *fx);

/* receive_time_unitu.c */
int	receive_time_unity(t_client *cl, t_graph *fx);

/* set_players_infos.c */
void set_player_action(int p_id, int action, t_client *cl);
void set_player_position(int p_id, int x, int y, int o, t_client *cl);
void set_player_level(int p_id, int level, t_client *cl);

/* start_client.c */
int	start_client(t_client *cl);

/* str_to_wortab.c */
char	**str_to_wordtab(char *str, char dif);

/* utils.c */
char	*my_strcat(char *str1, char *str2);
int	str_isnum(char *str);
int	tablen(char **tab);
void aff_tab(char **tab);
void aff_int_tab(int *tab);

/* xfunctions.c */
void	xclose(int fd);
int	xread(int fd, char *buf, int count);
void	*xmemset(char *addr, char c, size_t size);
void	*xmalloc(size_t size);
int tab_int_len(int *tab);
int	xerror(char *from);

#endif
