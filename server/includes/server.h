/*
** server.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __SERVER_H__
# define __SERVER_H__

# define CLIENT_GRAPHIC	"GRAPHIC"

# define READ_SIZE	2048
# define STD_BACKLOG	5

# define HEALTHCARE	"healthcare"
# define HEALTHCARE_T	126

# define T_CONN		(1 << 0)
# define T_READ		(1 << 1)
# define T_WRITE	(1 << 2)
# define T_FREE		(1 << 3)

# define MAX(a,b)	((a>b) ? (a) : (b))

# define USEC		100000

# include <sys/select.h>
# include <netinet/in.h>

# define ushort unsigned short
# define uchar	unsigned char

typedef struct		s_teams {
  ushort       		id_team;
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
  ushort       		nb_player;
  ushort       		food;
  ushort       		linemate;
  ushort       		deraumere;
  ushort       		sibur;
  ushort       		mendiane;
  ushort		phiras;
  ushort       		thystame;
  struct s_map		**map;
}			t_map;

typedef struct		s_msg {
  void			(*f)();
}			t_msg;

typedef struct		s_fdt {
  ushort       		type;
  t_msg			in;
  t_msg			out;
}			t_fdt;

typedef struct		s_network {
  ushort       		op_flags;
  int			port;
  ushort       		max_fd_used;
  ushort       		max_fd;
  t_fdt			**fdt;
  fd_set		r;
  fd_set		w;
  struct timeval	*timeout;
}			t_network;

typedef struct		s_bag {
  ushort       		linemate;
  ushort       		deraumere;
  ushort       		sibur;
  ushort       		mendiane;
  ushort       		phiras;
  ushort       		thystame;
  ushort       		food;
}			t_bag;

typedef struct		s_ringbuffer
{
    char       		*buffer;
    ushort     		wr_pointer;
    ushort     		rd_pointer;
    ushort     		size;
}			t_ringbuffer;

enum direction {
  DOWN,
  RIGHT,
  UP,
  LEFT
};

typedef struct		s_stack {
  char			*cmd;
  ushort       		fd_player;
  struct timeval	timestamp;
  struct s_stack	*next;
}			t_stack;

typedef struct		s_players {
  ushort       		fd_associate;
  ushort       		id_team;
  ushort       		level;
  ushort       		life;
  t_bag			*bag;
  int			posx;
  int			posy;
  int			stacksize;
  t_stack		*stacklast;
  t_ringbuffer	       	*wr_rb;
  t_ringbuffer		*rd_rb;
  enum direction       	direction;
  struct s_players	*next;
}			t_players;

typedef struct		s_cmds {
  short       		id;
  char			*cmd;
  void			(*f)();
  ushort       		duration;
}			t_cmds;

typedef struct		s_env {
  t_params		*params;
  t_map			*world;
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

void	       	add_player(t_env *e, ushort fd);
ushort	       	check_params(t_params *params);
ushort	       	init_connect_socket(t_network *network);
void	       	get_params(char **av, t_params *server);
t_map	       	*load_map(t_params *params);
t_network      	*load_network(t_params *params);
t_params       	*load_params(char **argv);
int	       	main(int argc, char **argv);
void	       	search_max_fd(t_network *e);
void	       	alloc_fd(t_network *network, ushort fd);
void	       	alloc_fdt(t_network *network);
void	       	set_max_fd(t_network *network, ushort fd);
void	       	close_fd(t_network *network, ushort fd);
void	       	new_connection(t_env *e, int fd_conn);
void	       	stdread(t_env *e, int fd);
void	       	stdwrite(t_env *e, int fd);
ushort	       	wait_clients(t_env *e);
ushort	       	check_player_cmd(t_env *e, t_players *player, char *cmd,
				 ushort len, ushort id);
t_players      	*get_player_byfd(t_env *e, ushort fd);
ushort	       	get_player_message(char **buf, ushort fd);
void	       	add_stack(t_env *e, t_players *player, char *cmd, ushort duration);
void		execute_stack(t_env *e);
ushort	       	check_player_team(t_env *e, t_players *player, char *cmd);
ushort		check_object_args(char *cmd);
ushort		check_msg_args(char *cmd);
ushort		check_incantation(t_env *e, t_players *player);
void		remove_player_stack(t_stack *execution, t_players *player);
void		clean_exit(t_env *e);
char		*get_args(char *cmd);
t_stack		*get_player_stacklast_byfd(t_env *e, ushort fd);
void		healthcare(t_env *e, t_players *player);
void	       	add_stack_healthcare(t_env *e, t_players *player,
	       			     char *cmd, ushort duration);
void		clean_player(t_env *e, t_players *player);

#endif
