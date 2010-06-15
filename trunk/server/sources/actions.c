/*
** actions.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:34:03 2010 amine mouafik
*/

#include <string.h>
#include <stdio.h>

#include "server.h"
#include "ringbuffer.h"

#define CMD_SIZE	512;

void	list_inventory(t_env *e, t_players *player)
{
  char	buff[512];

  e = e;
  sprintf(buff, "{nourriture %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	  player->bag->food, player->bag->linemate, player->bag->deraumere,
	  player->bag->sibur, player->bag->mendiane, player->bag->phiras, player->bag->thystame);
  rb_write(player->wr_rb, buff, strlen(buff));
}


void	broadcast(t_env *e, t_players *player)
{
  e = e;
  player = player;
}

void	incantation(t_env *e, t_players *player)
{
  char	buff[512];

  e = e;
  /* IF CHECK_INCANTATION */
  player->level++;
  sprintf(buff, "niveau actuel : %d\n", player->level);
  rb_write(player->wr_rb, buff, strlen(buff));
  /* envoie client graphique*/
  /* ELSE */
  sprintf(buff, "niveau actuel : %d\n", player->level);
  rb_write(player->wr_rb, buff, strlen(buff));
}

void	player_fork(t_env *e, t_players *player)
{
  e = e;
  player = player;
}
