/*
** get_team_infos.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Sun Jun 20 07:18:15 2010 amine mouafik
** Last update Sun Jun 20 07:21:00 2010 amine mouafik
*/

#include <stdlib.h>

#include "types.h"

char		*get_team_byid(t_env *e, int id_team)
{
  t_teams	*current;

  current = e->params->teams;
  while (current)
    {
      if (current->id_team == id_team)
	return (current->name);
      current = current->next;
    }
  return (NULL);
}
