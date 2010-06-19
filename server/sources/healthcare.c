/*
** healthcare.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun 14 14:52:14 2010 amine mouafik
** Last update Mon Jun 14 15:34:09 2010 amine mouafik
*/

#include "types.h"
#include "stack.h"
#include "ringbuffer.h"
#include "answers.h"
#include "healthcare.h"

void   	healthcare(t_env *e, t_players *player)
{
  player->bag->food--;
  if (player->bag->food <= 0)
    {
      rb_write(player->wr_rb, DEAD, DEAD_LEN);
      clean_player(e, player);
    }
  else
    add_stack_healthcare(e, player, HEALTHCARE, HEALTHCARE_T);
}