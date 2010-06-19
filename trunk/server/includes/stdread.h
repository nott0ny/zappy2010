/*
** stdread.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun 14 15:59:47 2010 amine mouafik
*/

#ifndef __STDREAD_H__
# define __STDREAD_H__

void		go_forward(t_env *e, t_players *player);
void		rotate_right(t_env *e, t_players *player);
void		rotate_left(t_env *e, t_players *player);
void		explore(t_env *e, t_players *player);
void		list_inventory(t_env *e, t_players *player);
void		take_object(t_env *e, t_players *player);
void		drop_object(t_env *e, t_players *player);
void		expulse(t_env *e, t_players *player);
void		broadcast(t_env *e, t_players *player);
void		incantation(t_env *e, t_players *player);
void		player_fork(t_env *e, t_players *player);
void		connect_nbr(t_env *e, t_players *player);
void		clean_player(t_env *e, t_players *player);
void		remove_player_stack(t_stack *execution, t_players *player);
t_players	*get_player_byfd(t_env *e, ushort fd);
ushort		get_player_message(char **buf, ushort fd);
ushort		check_player_team(t_env *e, t_players *player, char *cmd);
ushort		check_player_cmd(t_env *e, t_players *player,
				 char *cmd, ushort len, ushort id);
void	       	add_stack(t_env *e, t_players *player,
			  char *cmd, ushort duration);

#endif
