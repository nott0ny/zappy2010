#include <stdlib.h>

#include "client.h"

int		*get_list_id(char **params)
{
  int		i;
  int		j;
  int		*tab;
  
  tab = xmalloc(sizeof(int*) * (tablen(params) - 3));
  i = 4;
  j = 0;
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
  i = 0;
  while (temp)
    {
      if (temp->id == tab[i])
	{
	  temp->action = ACT_INC;
	  i++;
	}
      temp = temp->next;
    }
  i = 0;
  while (tab[i])
    aff_player(cl, tab[i++]);
  return (0);
}
