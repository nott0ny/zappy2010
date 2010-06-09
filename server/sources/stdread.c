/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Mon Jun  7 16:03:31 2010 amine mouafik
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
  {0, "avance\n", go_forward, 7},
  {1, "droite\n", rotate_right, 7},
  {2, "gauche\n" , rotate_left, 7},
  {3, "voir\n" , explore, 7},
  {4, "inventaire\n" , list_inventory, 1},
  {5, "prend" , take_object, 7},
  {6, "pose" , drop_object, 7},
  {7, "expulse\n" , expulse, 7},
  {8, "broatcast\n" , broadcast, 7},
  {9, "incantation\n" , incantation, 300},
  {10, "fork\n" , player_fork, 42},
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

  if (strncmp(cmd, gl_cmds[i].cmd, strlen(gl_cmds[i].cmd) - 1) == 0)
    {
      id_cmd = gl_cmds[i].id;
      if (id_cmd == PREND || id_cmd == POSE || id_cmd == INCANTATION)
	if (check_player_cmd(e, player, cmd) == -1)
	  return (1);
      add_cmd_onstack(e, player->fd_associate, gl_cmds[i].id, gl_cmds[i].duration);
      printf("%s[%d] Received : '%s'.%s\n",
	     CYAN, player->fd_associate, cmd, WHITE);
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
  if (player->team_name == NULL)
    player->team_name = (char *)strdup(cmd);
  while (gl_cmds[++i].id != -1)
    if (match_player_cmd(e, player, cmd, i))
      return ;
  printf("%s[%d] Received : unknown command.%s\n",
	 RED, player->fd_associate, WHITE);
  return ;
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
