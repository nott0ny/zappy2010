#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "client.h"

void		add_player_in_list(char **params, t_player **p)
{
  t_player	*temp;

  temp = xmalloc(sizeof(t_player));
  temp->id = atoi(params[1]);
  temp->pos_x = atoi(params[2]);
  temp->pos_y = atoi(params[3]);
  temp->o = atoi(params[4]);
  temp->level = atoi(params[5]);
  temp->team = params[6];
  temp->ress = NULL;
  temp->message = NULL;
  temp->action = 0;
  temp->status = 0;
  temp->next = *p;
  *p = temp;
}

void		add_player_in_map(char **params, t_client *cl)
{
  t_player	*temp;
  int		p_id;
  int		index_id;

  temp = cl->plist;
  p_id = atoi(params[1]);
  while (temp)
    {
      if (temp->id == p_id)
	if (((temp->pos_x >= 0) && (temp->pos_x <= cl->fx->size_x)) &&
	    ((temp->pos_y >= 0) && (temp->pos_y <= cl->fx->size_y)))
	  {
	    index_id = tab_int_len(cl->fx->map[temp->pos_x][temp->pos_y]->players_id);
	    cl->fx->map[temp->pos_x][temp->pos_y]->players_id[index_id] = temp->id;
	    printf("=> case %d %d player: %d\n", temp->pos_x, temp->pos_y,
		   cl->fx->map[temp->pos_x][temp->pos_y]->players_id[index_id]);
	  }
      temp = temp->next;
    }
}

int	cmd_pnw(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 7)
    return (0);
  add_player_in_list(params, &cl->plist);
  add_player_in_map(params, cl);
  aff_player(cl, 0);
  return (0);
}
