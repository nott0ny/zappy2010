/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Thu Jun 10 19:44:11 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "ringbuffer.h"
#include "colors.h"
#include "x.h"

t_cmds	gl_cmds[] = {
  {0, "avance", go_forward, 7},
  {1, "droite", rotate_right, 7},
  {2, "gauche", rotate_left, 7},
  {3, "voir", explore, 7},
  {4, "inventaire", list_inventory, 1},
  {5, "prend", take_object, 7},
  {6, "pose", drop_object, 7},
  {7, "expulse", expulse, 7},
  {8, "broatcast", broadcast, 7},
  {9, "incantation", incantation, 300},
  {10, "fork", player_fork, 42},
  {-1, 0, 0, 0}
};

static char	*clean_player_cmd(char *cmd)
{
  int		len;

  len = strlen(cmd);
  cmd[len - 2] = '\0';
  return (cmd);
}

static int	match_player_cmd(t_env *e, t_players *player, char *cmd, int i)
{
  int		id_cmd;
  int		len_cmd;

  len_cmd = strlen(gl_cmds[i].cmd);
  if (strncmp(cmd, gl_cmds[i].cmd, len_cmd) == 0)
    {
      id_cmd = gl_cmds[i].id;
      if (check_player_cmd(e, player, cmd, len_cmd, id_cmd) == -1)
	return (0);
      add_cmd_onstack(e, player->fd_associate, cmd, gl_cmds[i].duration);
      return (1);
    }
  return (0);
}

static void	manage_player_cmd(t_env *e, t_players *player, int cmdlen)
{
  char		*cmd;
  int		i;

  i = -1;
  cmd = Xmalloc((cmdlen + 1) * sizeof(char));
  rb_read(player->rd_rb, (unsigned char *)cmd, cmdlen);
  cmd = clean_player_cmd(cmd);
  if (!player->team_name)
    if (check_player_team(e, player, cmd))
      return ;
  while (gl_cmds[++i].id != -1)
    if (match_player_cmd(e, player, cmd, i) != 0)
      return ;
  printf("%s[%d] Received unknown command.%s\n",
	 RED, player->fd_associate, WHITE);
}

void		stdread(t_env *e,int fd)
{
  t_players	*player;
  char		*buf;
  int		len;

  len = get_player_message(&buf, fd);
  player = get_player_byfd(e, fd);
  if (player)
    {
      rb_write(player->rd_rb, (unsigned char *)buf, len);
      while ((len = rb_has_cmd(player->rd_rb)) > 0)
	manage_player_cmd(e, player, len);
    }
  free(buf);
}
