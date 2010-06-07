/*
** server.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun  7 16:08:56 2010 amine mouafik
*/

#ifndef __SERVER_H__
# define __SERVER_H__

# define SO_REUSEPORT 15 

# define CLIENT_GRAPHIC	"GRAPHIC"

# define ERR_MAP	"the world is too small"
# define ERR_TIME	"the speed must be between 1 and 1000000"
# define ERR_CLIENT	"you must allow at least one client per team"
# define ERR_TEAMS	"each team name must be unique"
# define ERR_TEAMS_RSV	"the team name "CLIENT_GRAPHIC" is reserved"
# define ERR_TEAMS_MIN	"you must create at least two teams"

# define DEFAULT_PORT	4242
# define DEFAULT_WIDTH	20
# define DEFAULT_HEIGHT	20
# define DEFAULT_CLIENT 1
# define DEFAULT_TIME	100
# define TIMEOUT	1

# define DENSITY_HIGH	10
# define DENSITY_LOW	30

# define WHITE		"\033[0;m"
# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define PURPLE		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define GREY		"\033[1;37m"

# define X(err, res, str)	(x(err, res, str, __FILE__, __LINE__))
# define _X(err, res, str)	(_x(err, res, str, __FILE__, __LINE__))
# define _XW(str)		(_xw(str))
# define Xmalloc(size)		(xmalloc(size, __FILE__, __LINE__))

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

typedef struct		s_players {
  int			fd_associate;
  char			*team_name;
  int			life;
  t_bag			*bag;
  int			posx;
  int			posy;
  struct s_players	*next;
}			t_players;

typedef struct		s_clients {
  int			cs;
  int			id;
  t_players		*players;
  struct s_clients	*next;
}			t_clients;

typedef struct		s_env {
  t_params		*params;
  t_map			**map;
  t_network		*network;
  t_players		*clients;
}			t_env;

void			add_player(t_env *e, int fd, char *t_name, int x, int y);
int			check_params(t_params *params);
int			init_connect_socket(t_network *network);
void			get_params(char **av, t_params *server);
t_map			**load_map(t_params *params);
t_network		*load_network(t_params *params);
t_params		*load_params(char **argv);
int			main(int argc, char **argv);

/* fix */
void			search_max_fd(t_network *e);
void			alloc_fd(t_network *network, int fd);
void			alloc_fdt(t_network *network);
void			set_max_fd(t_network *network, int fd);
void			close_fd(t_network *network, int fd);

void			new_connection(t_env *e, int fd_conn);
void			stdread(t_env *e,int fd);
int			wait_clients(t_env *e);

/* fix */
int			init_fds(t_env *e);
void			watch_fds(t_env *e);

void  	*x(void *err, void *res, char *str, char *file, int line);
void   	*_x(void *err, void *res, char *str, char *file, int line);
int	_xw(char *str);
void	*xmalloc(int size, char *file, int line);

#endif
