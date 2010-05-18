/*
** get_next_line2.c for  in /u/all/roux_a/cu/rendu/c/get_next_line
** 
** Made by alban roux
** Login   <roux_a@epitech.net>
** 
** Started on  Thu Oct 22 15:48:18 2009 alban roux
** Last update Thu May 13 18:49:33 2010 adrien veau-greiner
*/

#include "get_next_line.h"

void		resize(char *str, int i, int *index)
{
  int		ind;

  ind = -1;
  while (++ind < (*index - i))
    str[ind] = str[i + ind];
  *index -= i;
}

char		*getnl(char *str, int *index, const int fd)
{
  int		i;
  char		*ret;
  int		f;

  i = -1;
  f = 0;
  ret = 0;
  while (++i < *index)
    if (*(str + i) == '\0' || *(str + i) == '\n')
      {
	ret = malloc((i + 1) * sizeof(*ret) + 1);
	ret = strncpy(ret, str, i);
	ret[i + 1] = '\0';
	resize(str, i + 1, index);
	return (ret);
      }
  if (i == *index && i != 0)
    {
      ret = malloc(i * sizeof(*ret) + 1);
      ret = strncpy(ret, str, i);
      resize(str, i, index);
      ret = strcat(ret, gnl(fd, index, str));
      return (ret);
    }
  return (0);
}

char		*gnl(const int fd, int *index, char *buff)
{
  char		*tmp;
  int		offset;

  tmp = getnl(buff, index, fd);
  offset = 1;
  while (tmp == 0 && offset > 0)
    {
      if ((*index) + READ_B > BUFFER)
	offset = read(fd, buff + (*index), BUFFER - (*index));
      else
	offset = read(fd, buff + (*index), READ_B);
      if (offset > 0)
	(*index) += offset;
      tmp = getnl(buff, index, fd);
    }
  if (offset == 0 && tmp == 0 && (*index) > 0)
    {
      tmp = malloc(sizeof(*tmp) * (*index) + 1);
      tmp = strncpy(tmp , buff, (*index));
      tmp[*index] = 0;
      (*index) = 0;
    }
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static int	index = 0;
  static char	buff[BUFFER + 1];

  if (fd == -1)
    {
      index = 0;
      buff[0] = 0;
    }
  else
    return (gnl(fd, &index, buff));
  return (0);
}
