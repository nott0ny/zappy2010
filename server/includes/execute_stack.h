/*
** execute_stack.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Sun Jun 20 01:42:19 2010 amine mouafik
*/

#ifndef __EXECUTE_STACK_H__
# define __EXECUTE_STACK_H__

t_stack		*get_player_stacklast_byfd(t_env *e, short fd);
t_players	*get_player_byfd(t_env *e, short fd);
void		healthcare(t_env *e, t_players *player);

#endif
