/*
** check_player_cmd.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Sun Jun 20 05:51:50 2010 amine mouafik
*/

#ifndef __CHECK_PLAYER_CMD_H__
# define __CHECK_PLAYER_CMD_H__

# define PRENDRE	5
# define POSE		6
# define BROADCAST	8
# define INCANTATION	9

ushort 	check_object_args(char *cmd);
ushort 	check_msg_args(char *cmd);
ushort 	check_incantation(t_env *e, t_players *player, ushort callback);

#endif
