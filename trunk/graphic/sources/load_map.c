#include <SDL/SDL.h>
#include <stdlib.h>

#include "graphics.h"
#include "client.h"

void		blit_case(t_graph *fx, SDL_Rect pos, int x, int y)
{
  fx->map[x][y]->pos_x = pos.x;
  fx->map[x][y]->pos_y = pos.y;
  /* printf("case %d %d x:%d y:%d\n", x, y, fx->map[x][y]->pos_x, 
     fx->map[x][y]->pos_y);*/
  SDL_BlitSurface(fx->gui->scase, NULL, fx->gui->window, &pos);
}

void		load_map(t_client *cl)
{
  SDL_Rect	pos_y;
  SDL_Rect	pos_x;
  int		i;
  int		j;

  pos_x.x = (GAME_WINDOW_X / 2) - (CASE_W / 2);
  pos_x.y = 0;
  i = 0;
  j = 0;
  while (j < cl->fx->size_x)
    {
      i = 0;
      pos_y = pos_x;
      while (i < cl->fx->size_y)
	{
	  blit_case(cl->fx, pos_y, j, i++);
	  pos_y.x -= (CASE_W / 2);
	  pos_y.y += (CASE_H / 2) - 5;
	}
      pos_x.x += (CASE_W / 2);
      pos_x.y += (CASE_H / 2) - 8;
      j++;
    }
}
