
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
