#include <stdlib.h>
#include <stdio.h>

#include "client.h"

int		cmd_pbc(char **params, t_client *cl)
{
  t_player	*temp;
  int		p_id;

  aff_tab(params);
  if (tablen(params) < 3)
      return (0);
  temp = cl->plist;
  p_id = atoi(params[1]);
  while (temp)
    {
      if (temp->id == p_id)
	{
	  temp->action = ACT_BRD;
	  temp->message = params[2];
	}
      temp = temp->next;
    }
  aff_player(cl, p_id);
  return (0);
}
