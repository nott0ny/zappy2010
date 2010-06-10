#include <stdlib.h>

#include "client.h"

int	cmd_pdi(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 2)
    return (0);
  set_player_action(atoi(params[1]), ACT_DIE, cl);
  return (0);
}
