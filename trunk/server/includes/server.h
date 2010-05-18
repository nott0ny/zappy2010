/*
** server.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Thu May 13 16:37:33 2010 amine mouafik
*/

#ifndef __SERVER_H__
# define __SERVER_H__

# define CLIENT_GRAPHIC	"GRAPHIC"

# define DEFAULT_PORT	4242
# define DEFAULT_WIDTH	20
# define DEFAULT_HEIGHT	20
# define DEFAULT_CLIENT 1
# define DEFAULT_TIME	100

# define ERR_MAP	"the world is too small"
# define ERR_TIME	"the speed must be between 1 and 1000000"
# define ERR_CLIENT	"you must allow at least one client per team"
# define ERR_TEAMS	"each team name must be unique"
# define ERR_TEAMS_RSV	"the team name "CLIENT_GRAPHIC" is reserved"
# define ERR_TEAMS_MIN	"you must create at least two teams"

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

typedef struct		s_network {
  int			s;
  int			cs;
  u_int			csl;
  int			port;
  struct sockaddr_in	server;
  struct sockaddr_in	client;
  fd_set		rd;
  fd_set		wr;
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
  int			life;
  t_bag			*bag;
  int			posx;
  int			posy;
  struct s_player	*next;
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
  t_clients		*clients;
}			t_env;

int		manage_client(t_env *e);
int		wait_clients(t_env *e);

t_network	*load_network(t_params *params);

int		generate();
void		view_map(t_map **map, t_params *params);
t_map		**load_map(t_params *params);

int		check_mapsize(int width, int height);
int		check_timescale(int time);
int		check_teams_uniqueness(t_teams *teams);
int		check_params(t_params *params);

void		get_teams_name(char **av, int *i, t_params *server);
void		get_params(char **av, t_params *server);

t_params	*load_params(char **argv);
int		view_params(t_params *params);

int		init_params(t_params *params);

int		print_err(char *str);
void		*xmalloc(unsigned int size);

#endif
