/*
** init_ringbuffer.c for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/sources
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:17:56 2010 amine mouafik
** Last update Sun Jun 20 10:20:17 2010 amine mouafik
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#include "types.h"
#include "ringbuffer.h"
#include "utils.h"

ushort		rb_init(t_ringbuffer **rb, ushort size)
{
  t_ringbuffer	*ring;

  if (rb == NULL || size < BUF_SIZE)
    return (0);
  ring = Xmalloc(sizeof(t_ringbuffer));
  if (ring == NULL)
    return (0);
  ring->size = 1;
  while (ring->size <= size)
    ring->size <<= 1;
  ring->rd_pointer = 0;
  ring->wr_pointer = 0;
  ring->buffer = Xmalloc((ring->size + 1) * sizeof(char));
  *rb = ring;
  return (1);
}

ushort	rb_clear(t_ringbuffer *rb)
{
  X(NULL, memset(rb->buffer, 0, rb->size), "memset");
  rb->rd_pointer = 0;
  rb->wr_pointer = 0;
  return (0);
}
