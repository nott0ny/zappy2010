/*
** check_player_team.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __CHECK_PLAYER_TEAM_H__
# define __CHECK_PLAYER_TEAM_H__

int    	get_free_slots_byteam(t_env *e, int id_team);
void	add_stack_healthcare(t_env *e, t_players *player,
			     char *cmd, ushort duration);

#endif
