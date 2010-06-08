/*
** get_next_line2.c for  in /u/all/roux_a/cu/rendu/c/get_next_line
** 
** Made by alban roux
** Login   <roux_a@epitech.net>
** 
** Started on  Thu Oct 22 15:48:18 2009 alban roux
** Last update Tue Jun  8 22:59:04 2010 adrien veau-greiner
*/

#include <string.h>
#include <unistd.h>

#include "client.h"

void		receive_command(t_client *cl)
{
  int nb_rec;
  char temp[305];
  
  memset(temp, '\0', 305);
  nb_rec = read(cl->sock, temp, 10);
  printf("%s", temp);
  rb_write(cl->read_buff, (unsigned char*)temp, nb_rec);
}
