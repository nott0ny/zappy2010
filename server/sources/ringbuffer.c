#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include "server.h"
#include "ringbuffer.h"
#include "x.h"

int	calc_max(t_ringbuffer *rb)
{
  int	i;
  int	j;

  if (rb->buffer[rb->rd_pointer] != '\n')
    i  = rb->rd_pointer;
  else
    i  = rb->rd_pointer + 1;
  j = 0;
  while (i != rb->wr_pointer && rb->buffer[i] != '\n')
    {
      if (i > rb->size)
	i = -1;
      j++;
      i++;
    }
  if (j == 0)
    return 0;
  if (i == rb->wr_pointer)           
    return -1;
  return (j+1);
}

int	rb_init (t_ringbuffer **rb, int size)
{
    t_ringbuffer *ring;

    if (rb == NULL || size < BUF_SIZE)
      return (0);
    ring = Xmalloc(sizeof(t_ringbuffer));
    if (ring == NULL)
      return (0);
    memset(ring, 0, sizeof(t_ringbuffer));
    ring->size = 1;
    while (ring->size <= size)
      ring->size <<= 1;
    ring->rd_pointer = 0;
    ring->wr_pointer = 0;
    ring->buffer = Xmalloc(sizeof(char) * (ring->size));
    *rb = ring;
    return (1);
}

int	rb_write (t_ringbuffer *rb, unsigned char * buf, int len)
{
    int total;
    int i;
    
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
    return total;
}

int	rb_free (t_ringbuffer *rb)
{
    return (rb->size - 1 - rb_data_size(rb));
}


int	rb_read (t_ringbuffer *rb, unsigned char * buf, int max)
{
    int total;
    int i;

    total = rb_data_size(rb);
    if(max > total)
        max = total;
    else
        total = max;
    i = rb->rd_pointer;
    if(i + max > rb->size)
    {
        memcpy(buf, rb->buffer + i, rb->size - i);
        buf += rb->size - i;
        max -= rb->size - i;
        i = 0;
    }
    memcpy(buf, rb->buffer + i, max);
    buf[max] = '\0';
    rb->rd_pointer = i + max;
    return total;
}

int	rb_data_size (t_ringbuffer *rb)
{
    return ((rb->wr_pointer - rb->rd_pointer) & (rb->size-1));
}

int	rb_clear (t_ringbuffer *rb)
{
    memset(rb->buffer,0,rb->size);
    rb->rd_pointer=0;
    rb->wr_pointer=0;

    return 0;
}
