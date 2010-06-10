#include <stdlib.h>

#include "client.h"

int		cmd_plv(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 3)
    return (0);
  set_player_level(atoi(params[1]), atoi(params[2]), cl);
  aff_player(cl, atoi(params[1]));
  return (0);
}
