#include <stdlib.h>

#include "client.h"

int player_is_in_case(int x, int y, int p_id, t_client *cl)
{
  int i;

  i = 0;
  while (cl->fx->map[x][y]->players_id[i])
    {
      if (cl->fx->map[x][y]->players_id[i] == p_id)
	return (0);
      i++;
    }
  return (-1);
}
