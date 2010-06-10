/*
** load_map.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Wed May  5 18:34:02 2010 amine mouafik
** Last update Thu Jun 10 19:33:20 2010 amine mouafik
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "server.h"
#include "load_map.h"
#include "utils.h"

static int	generate()
{
  int		nb;

  nb = rand() % 100;
  if (nb < DENSITY_HIGH)
    return (2);
  else if (nb < (DENSITY_LOW + DENSITY_HIGH))
    return (1);
  return (0);
}

t_map	**load_map(t_params *params)
{
  t_map	**map;
  int	i;
  int	j;

  i = -1;
  srand(time(NULL));
  map = Xmalloc(params->height * sizeof(*map));
  while (++i < params->height)
    {
      j = -1;
      map[i] = Xmalloc(params->width * sizeof(**map));
      while (++j < params->width)
	{
	  map[i][j].food = 0;
	  map[i][j].linemate = generate();
	  map[i][j].deraumere = generate();
	  map[i][j].sibur = generate();
	  map[i][j].mendiane = generate();
	  map[i][j].phiras = generate();
	  map[i][j].thystame = generate();
	}
    }
  printf("%sGenerating world ... done%s\n", GREEN, WHITE);
  return (map);
}
