/*
** load_map.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Wed May  5 18:34:02 2010 amine mouafik
** Last update Mon Jun  7 15:53:45 2010 amine mouafik
*/

#include <openssl/rand.h>
#include <time.h>
#include <stdio.h>
#include "server.h"

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
  map = xmalloc(params->height * sizeof(*map));
  while (++i < params->height)
    {
      j = -1;
      map[i] = xmalloc(params->width * sizeof(**map));
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
