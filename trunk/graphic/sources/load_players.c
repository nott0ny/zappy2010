
#include <SDL/SDL.h>
#include <stdlib.h>

#include "graphics.h"
#include "client.h"

void		init_sprite_player(t_ui *gui, int orient, int lvl, int action)
{
  ;
}

void		blit_player(t_graph *fx, t_player *temp)
{
  SDL_Rect	pos;

  init_sprite_player(fx->gui, temp->o, temp->level, temp->action);
  printf("blit players on case %d %d\n", temp->pos_x, temp->pos_y);
  pos.x = fx->map[temp->pos_x][temp->pos_y]->pos_x;
  pos.y = fx->map[temp->pos_x][temp->pos_y]->pos_y;
  pos.x += (CASE_W / 2) - 10;
  pos.y += (CASE_H / 2) - 10;
  SDL_BlitSurface(fx->gui->player, NULL, fx->gui->window, &pos);
}

void		load_players(t_client *cl)
{
  t_player	*temp;

  temp = cl->plist;
  while (temp)
    {
      blit_player(cl->fx, temp);
      temp = temp->next;
    }
}
