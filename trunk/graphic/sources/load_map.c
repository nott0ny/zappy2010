#include <SDL/SDL.h>
#include <stdlib.h>

#include "graphics.h"
#include "client.h"

void		blit_random_ress(t_graph *fx, int ress, SDL_Rect pos)
{
  SDL_Rect	random_pos;
  int		min;
  int		max;
  
  min = pos.x + (CASE_W / 3) + 2;
  max = pos.x + 2 * (CASE_W / 3);
  random_pos.x = min + (rand() % (max - min));
  min = pos.y + (CASE_H / 3) + 2;
  max = pos.y + 2 * (CASE_W / 3);
  random_pos.y = min + (rand() % (max - min));
  SDL_BlitSurface(fx->gui->food, NULL, fx->gui->window, &random_pos);
}

void		load_ress_oncase(t_graph *fx, char *ress, SDL_Rect pos)
{
  int		i;
  int		j;
  int		nb_ress;

  i = 0;
  nb_ress = 0;
  while (ress[i] != '\0')
    {
      nb_ress = ress[i] - '0';
      printf("nb-ress %d\n", nb_ress);
      if (nb_ress > 0 && i == 0)
	{
	  j = 0;
	  while (j < nb_ress)
	    {
	      blit_random_ress(fx, i, pos);
	      j++;
	    }
	}
      i++;
    }
}

void		blit_case(t_graph *fx, SDL_Rect pos, int x, int y)
{
  fx->map[x][y]->pos_x = pos.x;
  fx->map[x][y]->pos_y = pos.y;
  printf("case %d %d x:%d y:%d\n", x, y, fx->map[x][y]->pos_x, 
	 fx->map[x][y]->pos_y);
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
	  pos_y.x -= (CASE_W / 2) + 1;
	  pos_y.y += (CASE_H / 2) - 3;
	  blit_case(cl->fx, pos_y, j, i);
	  load_ress_oncase(cl->fx, cl->fx->map[j][i++]->ress, pos_y);
	}
       pos_x.x += (CASE_W / 2);
       pos_x.y += (CASE_H / 2);
      j++;
    }
}
