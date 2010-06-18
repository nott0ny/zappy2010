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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "load_map.h"
#include "utils.h"

static ushort	generate_food(t_map *w)
{
  ushort       	nb;

  nb = rand() % PERCASE;
  w->food += ((w->food + nb) <= w->food) ? nb : (nb = 0);
  return (nb);
}

static ushort	generate_common(t_map *w, int stone)
{
  ushort       	nb;

  nb = rand() % PERCASE;
  if (stone == LINEMATE)
    w->linemate += ((w->linemate + nb) <= w->linemate) ? nb : (nb = 0);
  else if (stone == DERAUMERE)
    w->deraumere += ((w->deraumere + nb) <= w->deraumere) ? nb : (nb = 0);
  else if (stone == SIBUR)
    w->sibur += ((w->sibur + nb) <= w->sibur) ? nb : (nb = 0);
  else if (stone == PHIRAS)
    w->phiras += ((w->phiras + nb) <= w->phiras) ? nb : (nb = 0);
  return (nb);
}

static ushort	generate_uncommon(t_map *w, int stone)
{
  ushort       	nb;

  nb = rand() % PERCASE;
  if (stone == MENDIANE)
    w->mendiane += ((w->mendiane + nb) <= w->mendiane) ? nb : (nb = 0);
  else if (stone == THYSTAME)
    w->thystame += ((w->thystame + nb) <= w->thystame) ? nb : (nb = 0);
  return (nb);
}

void	fill_case(t_map *c, t_map *w)
{
  c->food = (!c->food) ? generate_food(w) : c->food;
  c->linemate = (!c->linemate) ? generate_common(w, LINEMATE) : c->linemate;
  c->deraumere = (!c->deraumere) ? generate_common(w, DERAUMERE) : c->deraumere;
  c->sibur = (!c->sibur) ? generate_common(w, SIBUR) : c->sibur;
  c->mendiane = (!c->mendiane) ? generate_uncommon(w, MENDIANE) : c->mendiane;
  c->phiras = (!c->phiras) ? generate_common(w, PHIRAS) : c->phiras;
  c->thystame = (!c->thystame) ? generate_uncommon(w, THYSTAME) : c->thystame;
}

t_map	*load_map(t_params *params)
{
  t_map	*world;
  int	i;
  int	j;

  i = -1;
  srand(time(NULL));
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
	fill_case(&(world->map[rand() % params->height][rand() % params->width])
		  , world);
    }
  printf("%sGenerating world ... done%s\n", GREEN, WHITE);
  return (world);
}
