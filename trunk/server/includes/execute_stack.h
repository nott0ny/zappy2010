/*
** execute_stack.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __EXECUTE_STACK_H__
# define __EXECUTE_STACK_H__

t_stack		*get_player_stacklast_byfd(t_env *e, ushort fd);
t_players	*get_player_byfd(t_env *e, ushort fd);
void		healthcare(t_env *e, t_players *player);

#endif
