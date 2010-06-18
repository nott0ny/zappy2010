/*
** load_params.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun  7 21:48:51 2010 alban roux
*/

#ifndef __LOAD_PARAMS_H__
# define __LOAD_PARAMS_H__

# define DEFAULT_PORT	4242
# define DEFAULT_WIDTH	20
# define DEFAULT_HEIGHT	20
# define DEFAULT_CLIENT 1
# define DEFAULT_TIME	100

void	get_params(char **av, t_params *server);
ushort	check_params(t_params *params);

#endif
