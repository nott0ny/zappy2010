#include <stdlib.h>

#include "client.h"

void set_player_action(int p_id, int action, t_client *cl)
{
  t_player *temp;

  temp = cl->plist;
  while (temp)
    {
      if (temp->id == p_id)
	temp->action = action;
      temp = temp->next;
    }
}

void set_player_position(int p_id, int x, int y, int o, t_client *cl)
{
  t_player *temp;

  temp = cl->plist;
  while (temp)
    {
      if (temp->id == p_id)
	{
	  temp->pos_x = x;
	  temp->pos_y = y;
	  temp->o = o;
	  temp->action = -1;
	}
      temp = temp->next;
    }
}

void set_player_level(int p_id, int level, t_clien *cl)
{
  t_player *temp;

  temp = cl->plist;
  while (temp)
    {
      if (temp->id == p_id)
	{
	  temp->level = level;
	  temp->action = ACT_LVL;
	}
      temp = temp->next;
    }
}
