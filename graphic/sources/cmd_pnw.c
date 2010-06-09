#include <stdlib.h>
#include <unistd.h>

#include "client.h"

void		add_player(char **params, t_player **p)
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

int	cmd_pnw(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 7)
    return (0);
  add_player(params, &cl->plist);
  aff_player(cl, 0);
  return (0);
}
