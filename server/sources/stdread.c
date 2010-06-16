/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Tue Jun 15 12:07:34 2010 amine mouafik
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"
#include "ringbuffer.h"
#include "answers.h"
#include "utils.h"

t_cmds	gl_cmds[] = {
  {0, "avance", go_forward, 7},
  {1, "droite", rotate_right, 7},
  {2, "gauche", rotate_left, 7},
  {3, "voir", explore, 7},
  {4, "inventaire", list_inventory, 1},
  {5, "prend", take_object, 7},
  {6, "pose", drop_object, 7},
  {7, "expulse", expulse, 7},
  {8, "broadcast", broadcast, 7},
  {9, "incantation", incantation, 300},
  {10, "fork", player_fork, 42},
  {-1, 0, 0, 0}
};

static char	*clean_player_cmd(char *cmd)
{
  ushort       	len;

  len = strlen(cmd);
  cmd[len - 1] = '\0';
  return (cmd);
}

static ushort	match_player_cmd(t_env *e, t_players *player, char *cmd, int i)
{
  ushort       	id_cmd;
  ushort       	len_cmd;

  len_cmd = strlen(gl_cmds[i].cmd);
  if (strncmp(cmd, gl_cmds[i].cmd, len_cmd) == 0)
    {
      id_cmd = gl_cmds[i].id;
      if (check_player_cmd(e, player, cmd, len_cmd, id_cmd) == 1)
	return (0);
      add_stack(e, player, cmd, gl_cmds[i].duration);
      return (1);
    }
  return (0);
}

static ushort	manage_player_cmd(t_env *e, t_players *player, int cmdlen)
{
  char		*cmd;
  ushort       	i;

  i = -1;
  cmd = Xmalloc((cmdlen + 1) * sizeof(char));
  rb_read(player->rd_rb, cmd, cmdlen);
  cmd = clean_player_cmd(cmd);
  if (!player->id_team)
    {
      if (check_player_team(e, player, cmd))
	return (1);
      else
	return (0);
    }
  while (gl_cmds[++i].id != -1)
    if (match_player_cmd(e, player, cmd, i) != 0)
      return (0);
  return (2);
}

static void	stdrbose(char *stdread, t_players *player, t_env *e, int ret)
{
  stdread = clean_player_cmd(stdread);
  if (ret == 2)
    {
      rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
      remove_player_stack(e->execution, player);
    }
  else if (ret == 1)
    rb_write(player->wr_rb, IGNORE, IGNORE_LEN);
  printf("[<-] Received from #%d : %s%s%s\n",
	 player->fd_associate, CYAN, stdread, WHITE);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}

void		stdread(t_env *e, int fd)
{
  t_players	*player;
  char		*buf;
  ushort       	len;
  ushort       	verbose;

  len = get_player_message(&buf, fd);
  player = get_player_byfd(e, fd);
  if (player)
    {
      rb_write(player->rd_rb, buf, len);
      while ((len = rb_has_cmd(player->rd_rb)) > 0)
	{
	  verbose = manage_player_cmd(e, player, len);
	  stdrbose(buf, player, e, verbose);
	}
    }
  free(buf);
}
