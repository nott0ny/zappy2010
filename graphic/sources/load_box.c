
#include <SDL/SDL.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "client.h"
#include "graphics.h"

void		blit_teams_name(t_client *cl)
{
  TTF_Font	*font;
  SDL_Rect	pos;
  SDL_Color	textcolor = {255, 255, 255};
  SDL_Surface	*txt;

  font = TTF_OpenFont("images/stonehen.ttf", 25);
  txt = TTF_RenderText_Solid(font, "Salut", textcolor);
  pos.x = 30;
  pos.y = (GAME_WINDOW_Y - BOX_H) + 70;
  SDL_BlitSurface(txt, NULL, cl->fx->gui->window, &pos);
}

void		load_box_info(t_client *cl)
{
  SDL_Surface	*box;
  SDL_Rect	pos;

  box = IMG_Load(IMG_BOX);
  pos.x = 0;
  pos.y = GAME_WINDOW_Y - BOX_H;
  SDL_BlitSurface(box, NULL, cl->fx->gui->window, &pos);
  blit_teams_name(cl);
  SDL_FreeSurface(box);
}
