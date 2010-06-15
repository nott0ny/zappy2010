
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_image.h>

#include "graphics.h"
#include "client.h"

void	init_sprite_action_nord(t_ui *gui, int lvl, int action)
{
  
  gui->player = IMG_Load(IMG_PLYR);
}

void	init_sprite_action_south(t_ui *gui, int lvl, int action)
{
  gui->player = IMG_Load(IMG_PLYR);
}

void	init_sprite_action_west(t_ui *gui, int lvl, int action)
{
  gui->player = IMG_Load(IMG_PLYR);
}

void	init_sprite_action_east(t_ui *gui, int lvl, int action)
{
  gui->player = IMG_Load(IMG_PLYR);
}
