/*
** healthcare.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun 14 14:52:14 2010 amine mouafik
** Last update Mon Jun 14 15:34:09 2010 amine mouafik
*/

#include "server.h"
#include "ringbuffer.h"
#include "answers.h"

void   	healthcare(t_env *e, t_players *player)
{
  player->bag->food--;
  printf("HEALTHCARE() :\n");
  if (player->bag->food <= 0)
    {
      printf(" - DEAD / CLEAN PLAYER\n");
      rb_write(player->wr_rb, DEAD, DEAD_LEN);
      clean_player(e, player);
    }
  else
    {
      printf(" - ANOTHER HEALTHCARE\n");
      add_stack_healthcare(e, player, HEALTHCARE, HEALTHCARE_T);
    }
}
