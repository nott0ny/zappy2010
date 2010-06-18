/*
** ringbuffer.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/serveur/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Fri Jun 18 15:44:24 2010 amine mouafik
*/

#ifndef __RINGBUFFER_H__
# define __RINGBUFFER_H__

# define READ_SIZE	25
# define BUF_SIZE	50

ushort	rb_init (t_ringbuffer **, ushort);
ushort	rb_write (t_ringbuffer *, char *, ushort);
ushort	rb_free (t_ringbuffer *);
ushort	rb_read (t_ringbuffer *, char *, ushort);
short	rb_has_cmd(t_ringbuffer *);
ushort	rb_data_size (t_ringbuffer *);
ushort	rb_clear (t_ringbuffer *);

#endif
