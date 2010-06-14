/*
** manage_display.c for manage_display in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Mon Jun 14 12:29:46 2010 adrien veau-greiner
** Last update Mon Jun 14 17:40:44 2010 adrien veau-greiner
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <unistd.h>

#include "client.h"
#include "graphics.h"

void		manage_event(t_client *cl)
{
  SDL_Event	e;

  if (SDL_PollEvent(&e) == 1)
    {
      if (e.type == SDL_QUIT)
	cl->ingame = 1;
    }
}

void		create_game_window(t_ui *gui)
{
  SDL_FreeSurface(gui->window);
  SDL_FreeSurface(gui->loading);
  gui->window =  SDL_SetVideoMode(GAME_WINDOW_X, GAME_WINDOW_Y,
				  WINDOW_BPP, SDL_HWSURFACE);
  SDL_WM_SetCaption(GAME_WIN_TITLE, NULL);
  SDL_FillRect(gui->window, &gui->window->clip_rect,
	       SDL_MapRGB(gui->window->format, 200, 200, 200));
}

void		load_map(t_client *cl)
{
  SDL_Rect	pos_y;
  SDL_Rect	pos_x;
  int		i;
  int		j;

  pos_x.x = (GAME_WINDOW_X / 2);
  pos_x.y = 0;
  i = 0;
  j = 0;
  while (j <= cl->fx->size_x)
    {
      i = 0;
      if (j > 0)
	{
	  pos_x.x += (CASE_W / 2);
	  pos_x.y += (CASE_H / 2);
	}
      pos_y = pos_x;
      while (i <= cl->fx->size_y)
	{
	  pos_y.x -= (CASE_W / 2);
	  pos_y.y += (CASE_H / 2);
	  SDL_BlitSurface(cl->fx->gui->scase, NULL, cl->fx->gui->window,
			  &pos_y);
	  i++;
	}
      j++;
    }
}

void		manage_display(t_client *cl)
{
  manage_event(cl);
  if (cl->status == CL_LOAD)
    {
      create_game_window(cl->fx->gui);
      printf("Loading Map...\n");
      load_map(cl);
      printf("Map Loaded\n");
      cl->status = CL_DISP;
    }
  if (cl->status == CL_DISP)
    {
      SDL_Flip(cl->fx->gui->window);
    }
}
