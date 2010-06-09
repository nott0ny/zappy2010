#include <stdlib.h>

#include "client.h"

int		cmd_ppo(char **params, t_client *cl)
{
  int		p_id;
  t_player	*temp;
  
  aff_tab(params);
  if (tablen(params) != 5)
    return (0);
  temp = cl->plist;
  p_id = atoi(params[1]);
  while (temp)
    {
      if (temp->id == p_id)
	{
	  temp->pos_x = atoi(params[2]);
	  temp->pos_y = atoi(params[3]);
	  temp->o = atoi(params[4]);
	}
      temp = temp->next;
    }
  aff_player(cl, p_id);
  return (0);
}
