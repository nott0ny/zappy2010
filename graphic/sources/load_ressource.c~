
#include <stdlib.h>
#include <SDL/SDL.h>

#include "graphics.h"
#include "client.h"

void		blit_rand_ress(t_ui *gui, SDL_Surface *icon, SDL_Rect pos)
{
  SDL_Rect	f_pos;
  int		min;
  int		max;

  min = pos.x + (CASE_W / 4);
  max = pos.x + (3 * (CASE_W / 4));
  f_pos.x = min + (rand() % (max - min));
  min = pos.y + (CASE_H / 4);
  max = pos.y + (2 * (CASE_H / 4));
  f_pos.y = min + (rand() % (max - min));
  SDL_BlitSurface(icon, NULL, gui->window, &f_pos);
}

void		blit_ressource(t_graph *fx, int ress, SDL_Rect pos)
{
  if (ress == 0)
    blit_rand_ress(fx->gui, fx->gui->food, pos);
  else if (ress == 1)
    blit_rand_ress(fx->gui, fx->gui->linemate, pos);
  else if (ress == 2)
    blit_rand_ress(fx->gui, fx->gui->deraumere, pos);
  else if (ress == 3)
    blit_rand_ress(fx->gui, fx->gui->sibur, pos);
  else if (ress == 4)
    blit_rand_ress(fx->gui, fx->gui->mendiane, pos);
  else if (ress == 5)
    blit_rand_ress(fx->gui, fx->gui->phiras, pos);
  else if (ress == 6)
    blit_rand_ress(fx->gui, fx->gui->thystame, pos);
}

void		load_ress_oncase(t_graph *fx, char *ress, SDL_Rect pos)
{
  int		i;
  int		j;
  int		nb_ress;

  i = 0;
  nb_ress = 0;
  if (!ress)
    return ;
  while (ress[i])
    {
      nb_ress = ress[i] - '0';
      if (nb_ress > 0)
	{
	  j = 0;
	  while (j < nb_ress)
	    {
	      blit_ressource(fx, i, pos);
	      j++;
	    }
	}
      i++;
    }
}

void	load_ressource(t_client *cl)
{
  SDL_Rect	pos_y;
  SDL_Rect	pos_x;
  int		i;
  int		j;
  
  pos_x.x = (GAME_WINDOW_X / 2) - (CASE_W / 2);
  pos_x.y = 0;
  j = 0;
  while (j < cl->fx->size_x)
    {
      i = 0;
      pos_y = pos_x;
      while (i < cl->fx->size_y)
	{
	  load_ress_oncase(cl->fx, cl->fx->map[j][i++]->ress, pos_y);
	  pos_y.x -= (CASE_W / 2);
	  pos_y.y += (CASE_H / 2) - 5;
	}
      pos_x.x += (CASE_W / 2);
      pos_x.y += (CASE_H / 2) - 8;
      j++;
    }
}
