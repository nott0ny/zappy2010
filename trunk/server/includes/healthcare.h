/*
** healthcare.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __HEALTHCHARE_H__
# define __HEALTHCARE_H__

void	clean_player(t_env *e, t_players *player);
void	add_stack_healthcare(t_env *e, t_players *player,
			     char *cmd, ushort duration);

#endif
