/*
** utils.h for zappy in /u/all/mouafi_a/cu/rendu/c/zappy2010/server/includes
**
** Made by amine mouafik
** Login   <mouafi_a@epitech.net>
**
** Started on  Tue May  4 22:10:54 2010 amine mouafik
** Last update Mon Jun  7 21:48:51 2010 alban roux
*/

#ifndef __UTILS_H__
# define __UTILS_H__

# define WHITE	"\033[0;m"
# define BLACK	"\033[1;30m"
# define RED   	"\033[1;31m"
# define GREEN 	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE  	"\033[1;34m"
# define PURPLE	"\033[1;35m"
# define CYAN  	"\033[1;36m"
# define GREY  	"\033[1;37m"

# define Xmalloc(size)		(xmalloc(size, __FILE__, __LINE__))
# define X(err, res, str)	(x((void *)err, (void *)res, str, __FILE__, __LINE__))
# define _X(err, res, str)	(_x((void *)err, (void *)res, str, __FILE__, __LINE__))
# define _XW(str)		(_xw(str))

void  	*x(void *err, void *res, char *str, char *file, int line);
void   	*_x(void *err, void *res, char *str, char *file, int line);
int	_xw(char *str);
void	*xmalloc(int size, char *file, int line);

#endif
