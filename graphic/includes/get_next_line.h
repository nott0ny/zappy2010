/*
** get_next_line.h for  in /u/all/roux_a/cu/rendu/c/get_next_line
** 
** Made by alban roux
** Login   <roux_a@epitech.net>
** 
** Started on  Thu Nov 12 13:28:19 2009 alban roux
** Last update Sun Nov 15 12:23:10 2009 alban roux
*/

#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

#define READ_B	512
#define BUFFER	4096

char	*gnl(const int fd, int *index, char *buff);
char	*get_next_line(const int fd);
char	*my_strncpy(char *dest, char *src, int n);
int	xread(int fd, void *buff, int size_buff);
char	*xcharset(char *b, int c, int nb);
void	*xmalloc(int size);
char	*my_strcat(char *str1, char *str2);
int	my_strlen(char *str);

#endif
