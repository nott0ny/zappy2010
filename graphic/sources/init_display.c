
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>

#include "client.h"
#include "graphics.h"

int		init_window(t_client *cl)
{
  cl->fx->gui->window = SDL_SetVideoMode(INIT_WINDOW_X, INIT_WINDOW_Y,
					 16, SDL_HWSURFACE);
  if (cl->fx->gui->window == NULL)
    return (-1);
  SDL_WM_SetCaption(INIT_WIN_TITLE, NULL);
  SDL_BlitSurface(cl->fx->gui->loading, NULL, cl->fx->gui->window, NULL);
  SDL_Flip(cl->fx->gui->window);
  return (0);
}

void	load_sprites(t_client *cl)
{
  cl->fx->gui->loading = IMG_Load(IMG_LOAD);
  cl->fx->gui->scase = IMG_Load(IMG_CASE);
}

int	init_display(t_client *cl)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      error(SDL_GetError());
      return (-1);
    }
  load_sprites(cl);
  if (init_window(cl) == -1)
    return (-1);
  return (0);
}
