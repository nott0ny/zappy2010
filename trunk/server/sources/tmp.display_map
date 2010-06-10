/*
** view_map.tmp.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Thu May 13 16:48:55 2010 amine mouafik
** Last update Thu May 13 16:52:43 2010 amine mouafik
*/

void	view_map(t_map **map, t_params *params)
{
  int	i;
  int	j;

  i = -1;
  while (++i < params->height)
    {
      j = -1;
      while (++j < params->width)
	{
	  printf("[%d][%d] food(%d) %slinemate(%d) %sderaumere(%d) " \
		 "%ssibur(%d) %smendiane(%d) %sphiras(%d) %sthystame(%d)%s\n",
		 i, j,
		 map[i][j].food, YELLOW,
		 map[i][j].linemate, BLUE,
		 map[i][j].deraumere, PURPLE,
		 map[i][j].sibur, CYAN,
		 map[i][j].mendiane, GREY,
		 map[i][j].phiras, RED,
		 map[i][j].thystame, WHITE);
	}
    }
  return ;
}
