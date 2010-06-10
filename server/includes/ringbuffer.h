/*
** ringbuffer.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun  7 21:48:51 2010 alban roux
*/

#ifndef __RINGBUFFER_H__
# define __RINGBUFFER_H__

# define BUF_SIZE	256

int	rb_init (t_ringbuffer **, int);
int	rb_write (t_ringbuffer *, unsigned char *, int);
int	rb_free (t_ringbuffer *);
int	rb_read (t_ringbuffer *, unsigned char *, int);
int	rb_has_cmd(t_ringbuffer *);
int	rb_data_size (t_ringbuffer *);
int	rb_clear (t_ringbuffer *);

#endif
