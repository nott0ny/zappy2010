
#include <SDL/SDL.h>
#include <stdlib.h>

#include "graphics.h"
#include "client.h"

void		load_line_grass(t_graph *fx, int y, SDL_Rect pos)
{
  int		j;

  j = 0;
  while (j < y)
    {
      SDL_BlitSurface(fx->gui->background, NULL,
		      fx->gui->window, &pos);
      pos.y += GRASS_SIZE;
      j++;
    }
}

void		load_background(t_graph *fx)
{
  SDL_Rect	pos_x;
  int		i;
  int		nb_x;
  int		nb_y;
  static int	init = 0;

  if (init == 0)
    {
      nb_x = (GAME_WINDOW_X / GRASS_SIZE) + GRASS_SIZE;
      nb_y = (GAME_WINDOW_Y / GRASS_SIZE) + GRASS_SIZE;
      i = 0;
      pos_x.x = 0;
      pos_x.y = 0;
      while (i < nb_x)
	{
	  load_line_grass(fx, nb_y, pos_x);
	  pos_x.x += GRASS_SIZE;
	  pos_x.y = 0;
	  i++;
	}
      init++;
    }
}
