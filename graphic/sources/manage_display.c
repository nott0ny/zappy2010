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
      if (e.type == SDL_MOUSEBUTTONUP)
	printf("molette:");
    }
}

void		manage_display(t_client *cl, int what)
{
  static int	i = 0;

  manage_event(cl);
  if (cl->status == CL_LOAD && what == 0)
    {
      load_background(cl->fx);
      load_map(cl);
      load_ressource(cl);
      load_players(cl);
      /*load_box_info(cl);*/
      SDL_Flip(cl->fx->gui->window);
    }
}
