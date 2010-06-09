#include <stdlib.h>

#include "client.h"

int		cmd_pex(char **params, t_client *cl)
{
  t_player	*temp;
  int		p_id;

  aff_tab(params);
  if (tablen(params) != 2)
    return (0);
  p_id = atoi(params[1]);
  while (temp)
    {
      if (temp->id == p_id)
	temp->action = ACT_EXP; 	
      temp = temp->next;
    }
  aff_player(cl, p_id);
  return (0);
}
