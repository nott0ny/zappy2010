#include <stdlib.h>

#include "client.h"

int		*get_list_id(char **params)
{
  int		i;
  int		j;
  int		*tab;
  
  i = 4;
  j = 0;
  tab = xmalloc(sizeof(int*) * (tablen(params) - 3));
  while (params[i])
    tab[j++] = atoi(params[i++]);
  return (tab);
}

int		cmd_pic(char **params, t_client *cl)
{
  t_player	*temp;
  int		*tab;
  int		i;

  aff_tab(params);
  if (tablen(params) < 5)
    return (0);
  tab = get_list_id(params);
  while (tab[i])
    {
      if (i == 0)
	set_player_action(tab[i], ACT_SINC, cl);
      else
	set_player_action(tab[i], ACT_INC, cl);
      aff_player(cl, tab[i]);
      i++;
    }
  return (0);
}
