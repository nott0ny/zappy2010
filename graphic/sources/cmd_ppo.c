#include <stdlib.h>
#include <stdio.h>

#include "client.h"

void		del_player_in_case(int x, int y, int p_id, t_client *cl)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (cl->fx->map[x][y]->players_id[i])
    {
      if (cl->fx->map[x][y]->players_id[i] == p_id)
	++i;
      cl->fx->map[x][y]->players_id[j++] = cl->fx->map[x][y]->players_id[i++];
    }
  printf("old ");
  aff_case(getpos_by_id(p_id, 0, cl), getpos_by_id(p_id, 1, cl), cl);
}

void		add_player_in_case(int x, int y, int p_id, t_client *cl)
{
  int		i;

  i = 0;
  while (cl->fx->map[x][y]->players_id[i])
    i++;
  if (player_is_in_case(x, y, p_id, cl) == -1)
    cl->fx->map[x][y]->players_id[i] = p_id;
  printf("new ");
  aff_case(x, y, cl);
}

void		move_player_in_map(char **params, t_client *cl)
{
  t_player	*temp;
  int		pos_y;
  int		pos_x;
  int		p_id;

  temp = cl->plist;
  pos_x = atoi(params[2]);
  pos_y = atoi(params[3]);
  p_id = atoi(params[1]);
  del_player_in_case(getpos_by_id(p_id, 0, cl),
		     getpos_by_id(p_id, 1, cl), p_id, cl);
  add_player_in_case(pos_x, pos_y, p_id, cl);
}

int		cmd_ppo(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 5)
    return (0);
  move_player_in_map(params, cl);
  set_player_position(atoi(params[1]), atoi(params[2]),
		      atoi(params[3]), atoi(params[4]), cl);
  aff_player(cl, atoi(params[1]));
  return (0);
}
