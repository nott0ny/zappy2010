/*
** aff.c for aff.c in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic/sources
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 13:18:31 2010 adrien veau-greiner
** Last update Wed Jun  9 20:40:57 2010 adrien veau-greiner
*/

#include <stdio.h>

#include "client.h"

void	aff_start()
{
  printf("%s \n%s\n\n", CLEAN_SCREEN, BANNER);
}

void	aff_player(t_client *cl, int id)
{
  t_player *temp;

  temp = cl->plist;
  while (temp)
    {
      if ((id != 0) && (temp->id == id))
	{
	  printf("player %d:\n\tpos_x: %d\n\tpos_y: %d\n\tteam: %s\n\torientation: %d\n\tlevel: %d\n\taction: %d\n\tmessage: %s\n", 
		 temp->id, temp->pos_x, temp->pos_y, temp->team, temp->o, temp->level, temp->action, temp->message);
	  break;
	}
      else if (id == 0)
	  printf("player %d:\n\tpos_x: %d\n\tpos_y: %d\n\tteam: %s\n\torientation: %d\n\tlevel: %d\n\taction: %d\n\tmessage: %s\n", 
		 temp->id, temp->pos_x, temp->pos_y, temp->team, temp->o, temp->level, temp->action, temp->message);
      temp = temp->next;
    }
}

int	aff_help(void)
{
  printf("\033[31mUsage: ./client-fx [-p port] [-h host]\033[00m\n");
  return (-1);
}
