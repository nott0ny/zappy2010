#include <stdlib.h>

#include "client.h"

int		cmd_plv(__attribute__((unused))char **params, __attribute__((unused))t_client *cl)
{
  t_player	*temp;
  int		p_id;

  aff_tab(params);
  if (tablen(params) != 3)
    return (0);
  temp = cl->plist;
  p_id = atoi(params[1]);
  while (temp)
    {
      if (temp->id == p_id)
	{
	  temp->level = atoi(params[2]);
	  temp->action = ACT_LVL;
	}
      temp = temp->next;
    }
  aff_player(cl, p_id);
  return (0);
}
