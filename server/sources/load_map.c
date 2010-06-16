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

#include "server.h"
#include "load_map.h"
#include "utils.h"

static ushort	generate_uncommon(t_map *world, t_params *params)
{
  ushort       	nb;

  nb = 1;
  params = params;
  return (nb);
}

static ushort	generate_common(t_map *world, t_params *params)
{
  ushort       	nb;

  nb = 0;
  params = params;
  return (nb);
}

static ushort	generate_food(t_map *world, t_params *params)
{
  ushort       	nb;

  nb = 1;
  params = params;
  return (nb);
}

void	fill_case(t_map *casemap, t_map *world, t_params *params)
{
  casemap->food = generate_food(world, params);
  casemap->linemate = generate_common(world, params);
  casemap->deraumere = generate_common(world, params);
  casemap->sibur = generate_common(world, params);
  casemap->mendiane = generate_uncommon(world, params);
  casemap->phiras = generate_common(world, params);
  casemap->thystame = generate_uncommon(world, params);
}

t_map	*load_map(t_params *params)
{
  t_map	*world;
  int	i;
  int	j;

  i = -1;
  srand(time(NULL));
  world = Xmalloc(sizeof(t_map));
  X(NULL, memset(world, 0, sizeof(t_map)), "memset");
  world->map = Xmalloc((params->height + 1) * sizeof(t_map));
  while (++i < params->height)
    {
      j = -1;
      world->map[i] = Xmalloc((params->width + 1) * sizeof(t_map));
      while (++j < params->width)
	fill_case(&(world->map[i][j]), world, params);
    }
  world->map[i] = NULL;
  printf("%sGenerating world ... done%s\n", GREEN, WHITE);
  return (world);
}
