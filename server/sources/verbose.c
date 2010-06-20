/*
** stdread.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Mon Jun  7 15:05:51 2010 amine mouafik
** Last update Sun Jun 20 11:25:59 2010 amine mouafik
*/

#include <sys/time.h>
#include <stdio.h>

#include "types.h"
#include "utils.h"

void	verbose(int output, int len, char *verbose, t_players *player)
{
  struct timeval	timestamp;

  gettimeofday(&timestamp, NULL);
  verbose[len - 1] = '\0';
  if (output)
    printf("[%d:%.6d][->] Sent to #%d : %s%s%s\n",
	   (int)timestamp.tv_sec, (int)timestamp.tv_usec,
	   player->fd_associate, PURPLE, verbose, WHITE);
  else
    printf("[%d:%.6d][<-] Received from #%d : %s%s%s\n",
	   (int)timestamp.tv_sec, (int)timestamp.tv_usec,
	   player->fd_associate, CYAN, verbose, WHITE);
}
