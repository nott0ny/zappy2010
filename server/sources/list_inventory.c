/*
** list_inventory.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Sun Jun 20 18:19:43 2010 amine mouafik
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "fdts.h"
#include "ringbuffer.h"

void	list_inventory(t_env *e, t_players *player)
{
  char	buff[WR_SIZE];

  e = e;
  sprintf(buff, "{nourriture %d, linemate %d, deraumere %d, sibur %d, " \
	  "mendiane %d, phiras %d, thystame %d}\n",
	  player->bag->food, player->bag->linemate, player->bag->deraumere,
	  player->bag->sibur, player->bag->mendiane, player->bag->phiras,
	  player->bag->thystame);
  rb_write(player->wr_rb, buff, strlen(buff));
  e->network->fdt[player->fd_associate]->type |= T_WRITE;
}
