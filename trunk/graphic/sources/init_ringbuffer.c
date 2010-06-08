/*
** init_ringbuffer.c for Zappy in /u/all/roux_a/cu/rendu/c/zappy/zappy2010/serveur/sources
** 
** Made by alban roux
** Login   <roux_a@epitech.net>
** 
** Started on  Tue May  4 22:17:56 2010 alban roux
** Last update Tue Jun  8 19:13:42 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "client.h"
#include "ringbuffer.h"

int		rb_init(t_ringbuffer **rb, int size)
{
  t_ringbuffer	*ring;

  if (rb == NULL || size < BUF_SIZE)
    return (0);
  ring = xmalloc(sizeof(t_ringbuffer));
  if (ring == NULL)
    return (0);
  memset(ring, 0, sizeof(t_ringbuffer));
  ring->size = 1;
  while (ring->size <= size)
    ring->size <<= 1;
  ring->rd_pointer = 0;
  ring->wr_pointer = 0;
  ring->buffer = xmalloc(sizeof(char) * (ring->size));
  *rb = ring;
  return (1);
}

int	rb_clear(t_ringbuffer *rb)
{
  memset(rb->buffer, 0, rb->size);
  rb->rd_pointer = 0;
  rb->wr_pointer = 0;
  return (0);
}
