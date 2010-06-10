/*
** server.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun  7 21:48:51 2010 alban roux
*/

#ifndef __SERVER_H__
# define __SERVER_H__

# define CLIENT_GRAPHIC	"GRAPHIC"
# define MSG_CO		"BIENVENUE\n"
# define OK		"ok\n"
# define KO		"ko\n"

# define DENSITY_HIGH	10
# define DENSITY_LOW	30

# define UP		1
# define LEFT		2
# define DOWN		3
# define RIGHT		4

#define MAX(a,b)	( (a>b)?(a):(b) )
#define READ_SIZE	2048
#define STD_BACKLOG	5

# include <sys/types.h>
# include <netinet/in.h>

typedef struct		s_teams {
  char			*name;
  struct s_teams	*next;
}			t_teams;

typedef struct		s_params {
  int			port;
  int			width;
  int			height;
  t_teams		*teams;
  int			maxclient;
  int			time;
}			t_params;

typedef struct		s_map {
  int			nb_player;
  int			food;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_map;

typedef struct		s_msg {
  void			(*f)();
}			t_msg;

typedef struct		s_fdt {
  int			type;
#define T_CONN	(1<<0)
#define T_READ	(1<<1)
#define T_WRITE	(1<<2)
#define T_FREE	(1<<3)
  t_msg			in;
  t_msg			out;
}			t_fdt;

#include <sys/select.h>

typedef struct		s_network {
  int			op_flags;
#define OP_V    (1<<0)
#define OP_U    (1<<1)
  int			port;
  int			max_fd_used;
  int			max_fd;
  t_fdt			**fdt;
  fd_set		r;
  fd_set		w;
  struct timeval	timeout;
}			t_network;

typedef struct		s_bag {
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_bag;

typedef struct		s_ringbuffer
{
    char       		*buffer;
    int			wr_pointer;
    int			rd_pointer;
    int			size;
}			t_ringbuffer;


typedef struct		s_players {
  int			fd_associate;
  char			*team_name;
  int			level;
  int			life;
  t_bag			*bag;
  int			posx;
  int			posy;
  short			direction;
  t_ringbuffer	       	*wr_rb;
  t_ringbuffer		*rd_rb;
  struct s_players	*next;
}			t_players;

typedef struct		s_cmds {
  int			id;
  char			*cmd;
  void			(*f)();
  int			duration;
}			t_cmds;

# define PRENDRE	5
# define POSE		6
# define INCANTATION	9

typedef struct		s_stack {
  struct timeval     	timestamp;
  char			*cmd;
  int			fd_player;
  struct s_stack	*next;
}			t_stack;

typedef struct		s_env {
  t_params		*params;
  t_map			**map;
  t_network		*network;
  t_players		*clients;
  t_stack		*execution;
}			t_env;

void		go_forward(t_env *e, t_players *player);
void		rotate_right(t_env *e, t_players *player);
void		rotate_left(t_env *e, t_players *player);
void		explore(t_env *e, t_players *player);
void		list_inventory(t_env *e, t_players *player);
void		take_object(t_env *e, t_players *player);
void		drop_object(t_env *e, t_players *player);
void		expulse(t_env *e, t_players *player);
void		broadcast(t_env *e, t_players *player);
void		incantation(t_env *e, t_players *player);
void		player_fork(t_env *e, t_players *player);
void	       	add_player(t_env *e, int fd);
int	       	check_params(t_params *params);
int	       	init_connect_socket(t_network *network);
void	       	get_params(char **av, t_params *server);
t_map	       	**load_map(t_params *params);
t_network      	*load_network(t_params *params);
t_params       	*load_params(char **argv);
int	       	main(int argc, char **argv);
void	       	search_max_fd(t_network *e);
void	       	alloc_fd(t_network *network, int fd);
void	       	alloc_fdt(t_network *network);
void	       	set_max_fd(t_network *network, int fd);
void	       	close_fd(t_network *network, int fd);
void	       	new_connection(t_env *e, int fd_conn);
void	       	stdread(t_env *e,int fd);
void	       	stdwrite(t_env *e,int fd);
int	       	wait_clients(t_env *e);
void	       	watch_fds(t_env *e);
int	       	check_player_cmd(t_env *e, t_players *player, char *cmd, int len, int id);
t_players      	*get_player_byfd(t_env *e, int fd);
int	       	get_player_message(char **buf, int fd);
void	       	add_cmd_onstack(t_env *e, int fd_player, char *cmd, int duration);
int	       	check_player_team(t_env *e, t_players *player, char *cmd);
int		check_object_arg(char *cmd);
int		check_incantation(t_env *e, t_players *player);

#endif
