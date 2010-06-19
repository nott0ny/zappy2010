/*
** types.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#include <sys/select.h>

#ifndef __TYPES_H__
# define __TYPES_H__

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

#endif
