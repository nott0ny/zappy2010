
#include <stdlib.h>

#include "client.h"

int get_action_by_id(int p_id, t_client *cl)
{
  t_player *temp;

  temp = cl->plist;
  while (temp)
    {
      if (temp->id == p_id)
	return (temp->action);
      temp = temp->next;
    }
  return (-1);
}

int   get_spell_by_id(int x, int y, t_client *cl)
{
  int i;

  i = 0;
  while (cl->fx->map[x][y]->players_id[i])
    {
      if (get_action_by_id(cl->fx->map[x][y]->players_id[i], cl) == ACT_SINC)
	return (cl->fx->map[x][y]->players_id[i]);
      i++;
    }
  return (-1);
}

int  getpos_by_id(int p_id, int opt, t_client *cl)
{
  t_player *temp;

  temp = cl->plist;
  while (temp)
    {
      if (temp->id == p_id)
	{
	  if (opt == 0)
	    return (temp->pos_x);
	  else if (opt == 1)
	    return (temp->pos_y);
	}
      temp = temp->next;
    }
  return (-1);
}
