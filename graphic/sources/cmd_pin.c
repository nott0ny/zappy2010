#include <stdlib.h>

#include "client.h"

int		cmd_pin(char **params, t_client *cl)
{
  t_player	*temp;
  int		p_id;

  aff_tab(params);
  if (tablen(params) != 11)
    return (0);
  temp = cl->plist;
  p_id = atoi(params[1]);
  while (temp)
    {
      if (temp->id == p_id)
	temp->ress = get_ressource(params, 4);
      temp = temp->next;
    }
  return (0);
}
