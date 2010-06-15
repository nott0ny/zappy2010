
#include <SDL/SDL.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>

#include "client.h"
#include "graphics.h"

void		load_box_info(t_client *cl)
{
  SDL_Surface	*box;
  SDL_Rect	pos;

  box = IMG_Load(IMG_BOX);
  pos.x = 0;
  pos.y = GAME_WINDOW_Y - BOX_H;
  SDL_BlitSurface(box, NULL, cl->fx->gui->window, &pos);
  SDL_FreeSurface(box);
}
