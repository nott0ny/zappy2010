/*
** check_player_team.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Sun Jun 20 07:21:28 2010 amine mouafik
*/

#ifndef __CHECK_PLAYER_TEAM_H__
# define __CHECK_PLAYER_TEAM_H__

char	*get_team_byid(t_env *e, int id_team);
int    	get_free_slots_byteam(t_env *e, int id_team);
short	add_graphic(t_env *e, t_players *player);
void	add_stack_healthcare(t_env *e, t_players *player,
			     char *cmd, ushort duration);

#endif
