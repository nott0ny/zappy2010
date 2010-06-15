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
  rb_write(player->wr_rb, (unsigned char *)"{");
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
  rb_write(player->wr_rb, (unsigned char *)"}\n");
  */
}

void	write_case_content(t_players *player, t_map c, int i)
{
  i = c.food;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" nourriture", strlen(" nourriture"));
  i = c.nb_player;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" joueur", strlen(" nourriture"));
  i = c.linemate;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" linemate", strlen(" nourriture"));
  i = c.deraumere;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" deraumere", strlen(" nourriture"));
  i = c.sibur;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" sibur", strlen(" nourriture"));
  i = c.mendiane;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" mendiane", strlen(" nourriture"));
  i = c.phiras;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" phiras", strlen(" phiras"));
  i = c.thystame;
  while (i--)
    rb_write(player->wr_rb, (unsigned char *)" thystame", strlen(" thystame"));
  rb_write(player->wr_rb, (unsigned char *)",", 1);
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
  rb_write(player->wr_rb, (unsigned char *)buff, strlen(buff));
}

void	take_object(t_env *e, t_players *player)
{
  char **tab_cmd;

  tab_cmd = str_to_wordtab(e->execution->cmd, ' ');
  if ((strcmp(tab_cmd[1], "nourriture") == 0) && e->map[player->posx][player->posy].food)
    {
      e->map[player->posx][player->posy].food--;
      player->bag->food++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "linemate") == 0) && e->map[player->posx][player->posy].linemate)
    {
      e->map[player->posx][player->posy].linemate--;
      player->bag->linemate++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "deraumere") == 0) && e->map[player->posx][player->posy].deraumere)
    {
      e->map[player->posx][player->posy].deraumere--;
      player->bag->deraumere++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "sibur") == 0) && e->map[player->posx][player->posy].sibur)
    {
      e->map[player->posx][player->posy].sibur--;
      player->bag->sibur++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "mendiane") == 0) && e->map[player->posx][player->posy].mendiane)
    {
      e->map[player->posx][player->posy].mendiane--;
      player->bag->mendiane++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "phiras") == 0) && e->map[player->posx][player->posy].phiras)
    {
      e->map[player->posx][player->posy].phiras--;
      player->bag->phiras++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "thystame") == 0) && e->map[player->posx][player->posy].thystame)
    {
      e->map[player->posx][player->posy].thystame--;
      player->bag->thystame++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else
    rb_write(player->wr_rb, (unsigned char *)MSG_FAILURE, strlen(MSG_FAILURE));
}

void	drop_object(t_env *e, t_players *player)
{
  char **tab_cmd;

  tab_cmd = str_to_wordtab(e->execution->cmd, ' ');
  if ((strcmp(tab_cmd[1], "nourriture") == 0) && player->bag->food)
    {
      e->map[player->posx][player->posy].food++;
      player->bag->food--;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "linemate") == 0) && player->bag->linemate)
    {
      e->map[player->posx][player->posy].linemate++;
      player->bag->linemate--;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "deraumere") == 0) && player->bag->deraumere)
    {
      e->map[player->posx][player->posy].deraumere--;
      player->bag->deraumere++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "sibur") == 0) && player->bag->sibur)
    {
      e->map[player->posx][player->posy].sibur--;
      player->bag->sibur++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "mendiane") == 0) && player->bag->mendiane)
    {
      e->map[player->posx][player->posy].mendiane--;
      player->bag->mendiane++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "phiras") == 0) && player->bag->phiras)
    {
      e->map[player->posx][player->posy].phiras--;
      player->bag->phiras++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else if ((strcmp(tab_cmd[1], "thystame") == 0) && player->bag->thystame)
    {
      e->map[player->posx][player->posy].thystame--;
      player->bag->thystame++;
      rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  /* envoie client graphic */
    }
  else
    rb_write(player->wr_rb, (unsigned char *)MSG_FAILURE, strlen(MSG_FAILURE));
}

void	expulse(t_env *e, t_players *player)
{
  t_players	*tmp;
  int		i;

  i = 0;
  tmp = e->clients;
  while (tmp)
    {
      if (tmp->posx == player->posx
	  && tmp->posy == player ->posy
	  && player->fd_associate != tmp->fd_associate)
	{
	  if (player->direction == UP)
	    {
	      if ((--tmp->posx) < 0)
		tmp->posx = e->params->width - 1;
	      /* envoie client graphic */
	    }
	  else if (player->direction == DOWN)
	    {
	      if ((++tmp->posx) >=  e->params->width)
		tmp->posx = 0;
	      /* envoie client graphic */
	    }
	  else if (player->direction == RIGHT)
	    {
	      if ((--tmp->posy) < 0)
		tmp->posy = e->params->height - 1;
	      /* envoie client graphic */
	    }
	  else if (player->direction == LEFT)
	    {
	      if ((++tmp->posy) >=  e->params->height)
		tmp->posy = 0;
	      /* envoie client graphic */
	    }
	  i++;
	}
      tmp = tmp->next;
    }
  if (i > 0)
    rb_write(player->wr_rb, (unsigned char *)MSG_SUCCESS, strlen(MSG_SUCCESS));
  else
    rb_write(player->wr_rb, (unsigned char *)MSG_FAILURE, strlen(MSG_FAILURE));
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
  rb_write(player->wr_rb, (unsigned char *)buff, strlen(buff));
  /* envoie client graphique*/
  /* ELSE */
  sprintf(buff, "niveau actuel : %d\n", player->level);
  rb_write(player->wr_rb, (unsigned char *)buff, strlen(buff));
}

void	player_fork(t_env *e, t_players *player)
{
  e = e;
  player = player;
}
