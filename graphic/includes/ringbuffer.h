

#ifndef __RINGBUFFER_H__
# define __RINGBUFFER_H__

# define BUF_SIZE	256

typedef struct s_ringbuffer
{
  char *buffer;
  int wr_pointer;
  int rd_pointer;
  int size;
}	       t_ringbuffer;

int	rb_init (t_ringbuffer **, int);
int	rb_write (t_ringbuffer *, unsigned char *, int);
int	rb_free (t_ringbuffer *);
int	rb_read (t_ringbuffer *, unsigned char *, int);

int	rb_has_cmd(t_ringbuffer *);
int	rb_data_size (t_ringbuffer *);
int	rb_clear (t_ringbuffer *);

#endif
