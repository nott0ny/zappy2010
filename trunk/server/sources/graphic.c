/*
** graphic.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 11:27:03 2010 amine mouafik
*/

#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

#include "types.h"
#include "ringbuffer.h"
#include "graphic.h"
#include "utils.h"

t_cmds	gl_graphic_cmds[] = {
  {0, "msz", map_size, 0},
  {1, "bct", case_content, 0},
  {2, "mct", map_content, 0},
  {3, "ppo", player_pos, 0},
  {4, "plv", player_level, 0},
  {5, "pin", player_inventory, 0},
  {6, "tna", teams_name, 0},
  {7, "sqt", get_time, 0},
  {8, "sst", set_time, 0},
  {-1, 0, 0, 0}
};

ushort	check_graphic_cmd(t_env *e, char *cmd, ushort len, ushort id)
{
  if (id == PLAYER_POS || id == PLAYER_LEVEL || id == PLAYER_INVENTORY)
    return (check_graphic_player(e, cmd));
  else if (id == CASE_CONTENT)
    return (check_graphic_case(e, cmd));
  else if (len == (int)strlen(cmd))
    return (0);
  return (1);
}

ushort	match_graphic_cmd(t_env *e, t_players *graphic, char *cmd, int i)
{
  ushort       	id_cmd;
  ushort       	len_cmd;

  len_cmd = strlen(gl_graphic_cmds[i].cmd);
  if (strncmp(cmd, gl_graphic_cmds[i].cmd, len_cmd) == 0)
    {
      id_cmd = gl_graphic_cmds[i].id;
      if (check_graphic_cmd(e, cmd, len_cmd, id_cmd) == 1)
	return (0);
      gl_graphic_cmds[i].f(e, graphic, cmd);
      return (1);
    }
  return (0);
}

ushort		get_graphic(t_env *e, t_players *graphic, char *cmd)
{
  short		i;

  i = -1;
  while (gl_graphic_cmds[++i].id != -1)
    if (match_graphic_cmd(e, graphic, cmd, i) != 0)
      return (0);
  return (2);
}

void	send_graphic(t_env *e, t_players *graphic, char *cmd)
{
  t_graphics	*current;

  if (graphic)
    send(graphic->fd_associate, cmd, strlen(cmd), 0);
  else
    {
      current = e->graphics;
      while (current)
	{
	  send(current->fd_associate, cmd, strlen(cmd), 0);
	  verbose(1, strlen(cmd), cmd, (t_players *)current);
	  current = current->next;
	}
    }
}

short	add_graphic(t_env *e, t_players *player)
{
  t_graphics	*graphic;

  graphic = Xmalloc(sizeof(t_graphics));
  graphic->fd_associate = player->fd_associate;
  graphic->wr_rb = player->rd_rb;
  graphic->rd_rb = player->rd_rb;
  graphic->next = e->graphics;
  e->graphics = graphic;
  player->id_team = -1;
  player->active = 0;
  player->level = 0;
  player->posx = -1;
  player->posy = -1;
  player->direction = 0;
  player->stacksize = 0;
  player->stacklast = NULL;
  printf("%sNew graphic client #%d successfully joined server.%s\n",
	 GREEN, graphic->fd_associate, WHITE);
  map_size(e, player, NULL);
  get_time(e, player, NULL);
  map_content(e, player, NULL);
  teams_name(e, player, NULL);
  return (-1);
}
