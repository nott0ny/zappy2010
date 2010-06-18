/*
** main.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/


#ifndef __MAIN_H__
# define __MAIN_H__

t_params	*load_params(char **argv);
t_map		*load_map(t_params *params);
t_network	*load_network(t_params *params);
ushort		wait_clients(t_env *e);

#endif
