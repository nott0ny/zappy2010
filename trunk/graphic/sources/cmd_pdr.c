#include <stdlib.h>

#include "client.h"

int	cmd_pdr(char **params, t_client *cl)
{
  aff_tab(params);
  if (tablen(params) != 3)
    return (0);
  set_player_action(atoi(params[1]), ACT_THR, cl); 
  return (0);
}
