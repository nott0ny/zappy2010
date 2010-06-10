#include <stdlib.h>

#include "client.h"

int		cmd_pex(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 2)
    return (0);
  set_player_action(atoi(params[1]), ACT_EXP, cl);
  aff_player(cl, atoi(params[1]));
  return (0);
}
