#include <stdlib.h>

#include "client.h"

int		cmd_plv(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 3)
    return (0);
  set_player_level(params[1], params[2], cl);
  aff_player(cl, params[1]);
  return (0);
}
