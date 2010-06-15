
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>

#include "client.h"
#include "graphics.h"

int		loading_window(t_client *cl)
{
  cl->fx->gui->window = SDL_SetVideoMode(GAME_WINDOW_X, GAME_WINDOW_Y,
					 WINDOW_BPP, SDL_HWSURFACE);
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
  cl->fx->gui->background = IMG_Load(IMG_BACK);
  cl->fx->gui->scase = IMG_Load(IMG_CASE);
  cl->fx->gui->food = IMG_Load(IMG_FOOD);
  cl->fx->gui->linemate = IMG_Load(IMG_STO1);
  cl->fx->gui->deraumere = IMG_Load(IMG_STO2);
  cl->fx->gui->sibur = IMG_Load(IMG_STO3);
  cl->fx->gui->mendiane = IMG_Load(IMG_STO4);
  cl->fx->gui->phiras = IMG_Load(IMG_STO5);
  cl->fx->gui->thystame = IMG_Load(IMG_STO6);
}

int	init_display(t_client *cl)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      error(SDL_GetError());
      return (-1);
    }
  load_sprites(cl);
  if (loading_window(cl) == -1)
    return (-1);
  return (0);
}
