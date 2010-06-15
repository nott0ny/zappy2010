
#include <stdio.h>

#include "client.h"

void	set_team_as_title(char *t1, char *t2)
{
  char	*title;

  title = xmalloc(sizeof(char) * (strlen(t1) + strlen(t2) +
				  strlen(GAME_WIN_TITLE)) + 3);
  title = strcat(t1, " Vs ");
  title = strcat(title, t2);
  title = strcat(title, " ");
  title = strcat(title, GAME_WIN_TITLE);
  SDL_WM_SetCaption(title, NULL);
  free(title);
}

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
      set_team_as_title(cl->team_name1, cl->team_name2);
    }
  return (0);
}
