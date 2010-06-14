
#include <stdio.h>

#include "client.h"

int	cmd_tna(char **params, t_client *cl)
{
  static int i = 0;

  if (tablen(params) != 2)
    return (0);
  if (i == 0)
    {
      cl->team_name1 = params[1];
      printf("team1: %s\n", cl->team_name1);
      i++;
    }
  else
    {
      if (strcmp(cl->team_name1, params[1]) != 0)
	cl->team_name2 = params[1];
      else
	return (-1);
      printf("team2: %s\n", cl->team_name2);
      cl->status = CL_LOAD;
    }
  return (0);
}
