/*
** load_map.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Wed May  5 18:34:02 2010 amine mouafik
** Last update Thu Jun 10 19:33:20 2010 amine mouafik
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "load_map.h"
#include "utils.h"

static int      generate(int rarety)
{
  int           nb;

  rarety = rarety;
  nb = rand() % 100;
  if (nb < DENSITY_HIGH)
    return (2);
  else if (nb < (DENSITY_LOW + DENSITY_HIGH))
    return (1);
  return (0);
}

t_map   *load_map(t_params *params)
{
  t_map *world;
  int   i;
  int   j;

  i = -1;
  srand(time(NULL) * getpid());
  world = Xmalloc(sizeof(t_map));
  world->map = Xmalloc((params->height + 1) * sizeof(t_map));
  while (++i < params->height)
    world->map[i] = Xmalloc((params->width + 1) * sizeof(t_map));
  world->map[i] = NULL;
  i = -1;
  while (++i < params->height)
    {
      j = -1;
      while (++j < params->width)
        {
	  world->map[i][j].nb_player = 0;
          world->map[i][j].food = generate(1);
          world->map[i][j].linemate = generate(2);
          world->map[i][j].deraumere = generate(2);
          world->map[i][j].sibur = generate(2);
          world->map[i][j].mendiane = generate(0);
          world->map[i][j].phiras = generate(2);
          world->map[i][j].thystame = generate(0);
        }
    }
  printf("%sGenerating world ... done%s\n", GREEN, WHITE);
  return (world);
}
