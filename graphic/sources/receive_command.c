/*
** get_next_line2.c for  in /u/all/roux_a/cu/rendu/c/get_next_line
** 
** Made by alban roux
** Login   <roux_a@epitech.net>
** 
** Started on  Thu Oct 22 15:48:18 2009 alban roux
** Last update Wed Jun  9 16:48:05 2010 adrien veau-greiner
*/

#include <string.h>
#include <unistd.h>

#include "client.h"

void		receive_command(t_client *cl)
{
  int nb_rec;
  char temp[MAXCMD_LEN];
  
  memset(temp, 0, MAXCMD_LEN);
  nb_rec = read(cl->sock, temp, MAXCMD_LEN);
  rb_write(cl->read_buff, (unsigned char*)temp, nb_rec);
}
