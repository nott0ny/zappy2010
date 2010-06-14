
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>

#include "client.h"
#include "graphics.h"

int		init_window(t_client *cl)
{
  SDL_Surface	*fond;
  SDL_Surface	*temp;

  cl->fx->gui->window = SDL_SetVideoMode(640, 400, 16, SDL_HWSURFACE);
  if (cl->fx->gui->window == NULL)
    return (-1);
  SDL_WM_SetCaption("Zappy-Bibicy FX", NULL);
  if ((temp = IMG_Load(LOADING_IMAGE)) != NULL)
    {
      fond = SDL_DisplayFormat(temp);
      SDL_FreeSurface(temp);
    }
  SDL_BlitSurface(fond, NULL, cl->fx->gui->window, NULL);
  SDL_Flip(cl->fx->gui-window);
  return (0);
}

int	init_display(t_client *cl)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      error(SDL_GetError());
      return (-1);
    }
  atexit(SDL_Quit);
  if (init_window(cl) == -1)
    return (-1);
  SDL_Delay(3000);
  return (0);
}
