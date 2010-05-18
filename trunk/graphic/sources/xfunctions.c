/*
** xutils.c for xutils in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 22:08:38 2010 adrien veau-greiner
** Last update Thu May 13 22:23:04 2010 adrien veau-greiner
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "client.h"

void	xclose(int fd)
{
  if (close(fd) == -1)
    {
      error("close");
      exit(EXIT_FAILURE);
    }
  return ;
}

int	xread(int fd, char *buf, int count)
{
  int	len_read;

  if ((len_read = read(fd, buf, count)) < 0)
    {
      error("read");
      exit(EXIT_FAILURE);
    }
  return (len_read);
}

void	*xmemset(char *addr, char c, size_t size)
{
  if ((addr = memset(addr, c, size)) == NULL)
    {
      error("memset");
      exit(EXIT_FAILURE);
    }
  return (addr);
}

void	*xmalloc(size_t size)
{
  void	*addr;

  if ((addr = malloc(size)) == NULL)
    nerror("malloc");
  return (addr);
}

int	xerror(char *from)
{
  fprintf(stderr, "Error from %s: %s\n", from, strerror(errno));
  exit(EXIT_FAILURE);
  return (-1);
}
