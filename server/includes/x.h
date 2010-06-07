/*
** x.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/includes
** 
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
** 
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun  7 21:48:51 2010 alban roux
*/

#ifndef __X_H__
# define __X_H__

# define X(err, res, str)	(x(err, res, str, __FILE__, __LINE__))
# define _X(err, res, str)	(_x(err, res, str, __FILE__, __LINE__))
# define _XW(str)		(_xw(str))
# define Xmalloc(size)		(xmalloc(size, __FILE__, __LINE__))

void  	*x(void *err, void *res, char *str, char *file, int line);
void   	*_x(void *err, void *res, char *str, char *file, int line);
int	_xw(char *str);
void	*xmalloc(int size, char *file, int line);

#endif
