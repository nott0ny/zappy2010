/*
** manage_ringbuffer.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:17:56 2010 amine mouafik
** Last update Sun Jun 20 10:20:35 2010 amine mouafik
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

#include "types.h"
#include "ringbuffer.h"
#include "utils.h"

short		rb_has_cmd(t_ringbuffer *rb)
{
  ushort	i;
  ushort	j;

  j = 1;
  if (rb->rd_pointer == rb->wr_pointer)
    return (0);
  i = rb->rd_pointer;
  while (i != rb->wr_pointer && rb->buffer[i] != '\n')
    {
      i++;
      j++;
      if (i >= rb->size)
	i = 0;
    }
  if (rb->buffer[i] == '\n')
    return (j);
  else if (i == rb->wr_pointer && j == rb->size - 1)
    return (-1);
  return (0);
}

ushort		rb_write (t_ringbuffer *rb, char *buf, ushort len)
{
  ushort	total;
  int		i;

  total = rb_free(rb);
  if (len > total)
    len = total;
  else
    total = len;
  i = rb->wr_pointer;
  if (i + len > rb->size)
    {
      memcpy(rb->buffer + i, buf, rb->size - i);
      buf += rb->size - i;
      len -= rb->size - i;
      i = 0;
    }
  memcpy(rb->buffer + i, buf, len);
  rb->wr_pointer = i + len;
  return (total);
}

ushort	rb_free(t_ringbuffer *rb)
{
  return (rb->size - 1 - rb_data_size(rb));
}

ushort		rb_read(t_ringbuffer *rb, char * buf, ushort max)
{
  ushort	total;
  int		i;

  total = rb_data_size(rb);
  if (max > total)
    max = total;
  else
    total = max;
  i = rb->rd_pointer;
  if (i + max > rb->size)
    {
      memcpy(buf, rb->buffer + i, rb->size - i);
      buf += rb->size - i;
      max -= rb->size - i;
      i = 0;
    }
  memcpy(buf, rb->buffer + i, max);
  buf[max] = '\0';
  rb->rd_pointer = i + max;
  return (total);
}

ushort	rb_data_size(t_ringbuffer *rb)
{
  return ((rb->wr_pointer - rb->rd_pointer) & (rb->size - 1));
}
