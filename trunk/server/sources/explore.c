/*
** explore.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources/
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 14:58:20 2010 amine mouafik
** Last update Thu Jun 10 19:34:03 2010 amine mouafik
*/

#include <string.h>

#include "server.h"
#include "ringbuffer.h"

t_map	*get_case_front(t_env *e, t_players *player, int level, int cx)
{
  int  	x;
  int  	y;

  x = (player->direction == LEFT) ? player->posx - level + cx : 0;
  y = (player->direction == LEFT) ? player->posy - level : 0;
  x = (player->direction == RIGHT) ? player->posx + level + cx : x;
  y = (player->direction == RIGHT) ? player->posy + level : y;
  x = (player->direction == UP) ? player->posx + level : x;
  y = (player->direction == UP) ? player->posy - level + cx : y;
  x = (player->direction == DOWN) ? player->posx - level : x;
  y = (player->direction == DOWN) ? player->posy + level - cx : y;
  x = (x < 0) ? e->params->width + x : x;
  x = (x > e->params->width - 1) ? x - e->params->width : x;
  y = (y < 0) ? e->params->height + y : y;
  y = (y > e->params->height - 1) ? y - e->params->height : y;
  return (&(e->world->map[x][y]));
}

void	write_case_content(t_players *player, t_map *c, int i)
{
  i = c->food;
  while (i--)
    rb_write(player->wr_rb, " nourriture", strlen(" nourriture"));
  i = c->nb_player;
  while (i--)
    rb_write(player->wr_rb, " joueur", strlen(" joueur"));
  i = c->linemate;
  while (i--)
    rb_write(player->wr_rb, " linemate", strlen(" linemate"));
  i = c->deraumere;
  while (i--)
    rb_write(player->wr_rb, " deraumere", strlen(" deraumere"));
  i = c->sibur;
  while (i--)
    rb_write(player->wr_rb, " sibur", strlen(" sibur"));
  i = c->mendiane;
  while (i--)
    rb_write(player->wr_rb, " mendiane", strlen(" mendiane"));
  i = c->phiras;
  while (i--)
    rb_write(player->wr_rb, " phiras", strlen(" phiras"));
  i = c->thystame;
  while (i--)
    rb_write(player->wr_rb, " thystame", strlen(" thystame"));
}

void	explore(t_env *e, t_players *player)
{
  int	i;
  int	j;
  int	nb;

  i = 0;
  rb_write(player->wr_rb, "{", 1);
  write_case_content(player, &(e->world->map[player->posx][player->posy]), i);
  rb_write(player->wr_rb, ",", 1);
  while (i < player->level)
    {
      j = 0;
      nb = 3 + (i * 2);
      while (j < nb)
	{
	  write_case_content(player, get_case_front(e, player, i + 1, j++), i);
	  if (!(j == nb && (i + 1) == player->level))
	    rb_write(player->wr_rb, ",", 1);
	}
      i++;
    }
  rb_write(player->wr_rb, "}\n", 2);
}
