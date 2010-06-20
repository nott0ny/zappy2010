/*
** graphic.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Sun Jun 20 11:26:07 2010 amine mouafik
*/

#ifndef __GRAPHIC_H__
# define __GRAPHIC_H__

# define CLIENT_GRAPHIC	"GRAPHIC"

# define CASE_CONTENT		1
# define PLAYER_POS		3
# define PLAYER_LEVEL		4
# define PLAYER_INVENTORY	5

void		map_size(t_env *e, t_players *graphic, char *cmd);
void		case_content(t_env *e, t_players *graphic, char *cmd);
void		map_content(t_env *e, t_players *graphic, char *cmd);
void		player_pos(t_env *e, t_players *graphic, char *cmd);
void		player_level(t_env *e, t_players *graphic, char *cmd);
void		player_inventory(t_env *e, t_players *graphic, char *cmd);
void		teams_name(t_env *e, t_players *graphic, char *cmd);
void		get_time(t_env *e, t_players *graphic, char *cmd);
void		set_time(t_env *e, t_players *graphic, char *cmd);
char		*get_args(char *cmd);
void		send_graphic(t_env *e, t_players *graphic, char *cmd);
t_players	*get_player_byfd(t_env *e, short fd);
ushort		check_graphic_player(t_env *e, char *cmd);
ushort		check_graphic_case(t_env *e, char *cmd);
ushort		cmd_count(char *cmd);
void		verbose(int output, int len, char *verbose, t_players *player);

#endif
