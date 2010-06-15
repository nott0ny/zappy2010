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

void	explore(t_env *e, t_players *player)
{
  int	i;
  int	j;
  int	nb;

  e = e;
  player = player;
  i = 0;
  j = 0;
  nb = 0;
  /*
  i = 0;
  rb_write(player->wr_rb, "{");
  write_case_content(&(e->map[player->posx][player->posy]), i);
  for (i = 0; i < player->level; i++)
    {
      nb = 3 + (i * 2);
      for (j = 0; j < nb; j++)
	{
	  if (strlen(res) < BUF_SIZE - 10)
	    write_case_content(get_case_front(e, player, i + 1, j), i);
	  else
	    break;
	}
    }
  rb_write(player->wr_rb, "}\n");
  */
}

void	write_case_content(t_players *player, t_map c, int i)
{
  i = c.food;
  while (i--)
    rb_write(player->wr_rb, " nourriture", strlen(" nourriture"));
  i = c.nb_player;
  while (i--)
    rb_write(player->wr_rb, " joueur", strlen(" nourriture"));
  i = c.linemate;
  while (i--)
    rb_write(player->wr_rb, " linemate", strlen(" nourriture"));
  i = c.deraumere;
  while (i--)
    rb_write(player->wr_rb, " deraumere", strlen(" nourriture"));
  i = c.sibur;
  while (i--)
    rb_write(player->wr_rb, " sibur", strlen(" nourriture"));
  i = c.mendiane;
  while (i--)
    rb_write(player->wr_rb, " mendiane", strlen(" nourriture"));
  i = c.phiras;
  while (i--)
    rb_write(player->wr_rb, " phiras", strlen(" phiras"));
  i = c.thystame;
  while (i--)
    rb_write(player->wr_rb, " thystame", strlen(" thystame"));
  rb_write(player->wr_rb, ",", 1);
}

/*
t_invent	*get_case_front(t_env *e, t_player *player, int level, int cx)
{
  int		x;
  int		y;

  x = (player->orientation == UP) ? player.posx - level + cx : 0;
  y = (player->orientation == UP) ? player.posy - level : 0;
  x = (player->orientation == DOWN) ? player.posx + level - cx : x;
  y = (player->orientation == DOWN) ? player.posy + level : y;
  x = (player->orientation == RIGHT) ? player.posx - level : x;
  y = (player->orientation == RIGHT) ? player.posy + level - cx : y;
  x = (player->orientation == LEFT) ? player.posx + level : x;
  y = (player->orientation == LEFT) ? player.posy - level + cx : y;
  if (x < 0)
    x = e->params->width + x;
  if (x > e->width - 1)
    x = x - e->params->width;
  if (y < 0)
    y = e->params->height + y;
  if (y > e->params->height - 1)
    y = y - e->params->height;
  return (&(e->map[y][x]));
}
*/

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
