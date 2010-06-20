/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Sun Jun 20 19:16:26 2010 amine mouafik
*/

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "stack.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "answers.h"
#include "utils.h"
#include "stdread.h"

t_cmds	gl_cmds[] = {
  {0, "avance", go_forward, GO_FORWARD_T},
  {1, "droite", rotate_right, ROTATE_RIGHT_T},
  {2, "gauche", rotate_left, ROTATE_LEFT_T},
  {3, "voir", explore, EXPLORE_T},
  {4, "inventaire", list_inventory, LIST_INVENTORY_T},
  {5, "prend", take_object, TAKE_OBJECT_T},
  {6, "pose", drop_object, DROP_OBJECT_T},
  {7, "expulse", expulse, EXPULSE_T},
  {8, "broadcast", broadcast, BROADCAST_T},
  {9, "incantation", incantation, INCANTATION_T},
  {10, "fork", player_fork, FORK_T},
  {11, "connect_nbr", connect_nbr, CONNECT_NBR_T},
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
  verbose(0, cmdlen, cmd, player);
  if (!player->id_team)
    {
      if (check_player_team(e, player, cmd))
	return (1);
      else
	return (0);
    }
  if (player->id_team == -1)
    return (get_graphic(e, player, cmd));
  while (gl_cmds[++i].id != -1)
    if (match_player_cmd(e, player, cmd, i) != 0)
      return (0);
  return (2);
}

static void	manage_ko(char *stdread, t_players *player, t_env *e, int ret)
{
  stdread = clean_player_cmd(stdread);
  if (ret == 2)
    {
      rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
      remove_player_stack(e->execution, player);
    }
  else if (player->id_team < 0)
    return ;
  else if (ret == 1)
    rb_write(player->wr_rb, FAILURE, FAILURE_LEN);
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}

void		stdread(t_env *e, int fd)
{
  t_players	*player;
  char		*buf;
  short		len;
  ushort	ko;

  buf = Xmalloc(RD_SIZE * sizeof(char));
  player = get_player_byfd(e, fd);
  if ((len = recv(fd, buf, RD_SIZE, 0)) <= 0)
    {
      clean_player(e, player);
      return ;
    }
  if (player)
    {
      rb_write(player->rd_rb, buf, len);
      while ((len = rb_has_cmd(player->rd_rb)) > 0)
	{
	  ko = manage_player_cmd(e, player, len);
	  manage_ko(buf, player, e, ko);
	}
    }
  free(buf);
}
