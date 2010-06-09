#include "server.h"

void	go_forward(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
  e->map[player->posx][player->poxy]->nb_player--;
  if (player->direction == UP)
    {
      if ((--player->posx) < 0)
	player->posx = e->params->width - 1;
    }
  else if (player->direction == DOWN)
    {
      if ((++player->posx) >=  e->params->width)
	player->posx = 0;
    }
  else if (player->direction == RIGHT)
    {
      if ((--player->posy) < 0)
	player->posx = e->params->height - 1;
    }
  else if (player->direction == LEFT)
    {
      if ((++player->posy) >=  e->params-height)
	player->posx = 0;
    }
  e->map[player->posx][player->poxy]++;
  rb_write(player->wr_rb, OK, strlen(OK));
}

void	rotate_right(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
  player->direction++;
  if (player->direction > 4)
    player->direction == 1;
  rb_write(player->wr_rb, OK, strlen(OK));
}

void	rotate_left(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
  player->direction--;
  if (player->direction < 1)
    player->direction == 4;
  rb_write(player->wr_rb, OK, strlen(OK));
}

void	explore(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
}

vid	list_inventory(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
}

void	take_object(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
  if ()
}

void	drop_object(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
}

void	expulse(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
}

void	broadcast(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
}

void	incantation(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
}

void	player_fork(__attribute__((unused))t_env *e, __attribute__((unused))t_players *player)
{
}
