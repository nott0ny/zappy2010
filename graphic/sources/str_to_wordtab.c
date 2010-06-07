/*
** str_to_wortab.c for str_to_wordtab in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:35:57 2010 adrien veau-greiner
** Last update Mon Jun  7 20:30:51 2010 adrien veau-greiner
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "client.h"

int	nb_word(char *str, char dif)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i] != '\0')
    {
      if (str[i] == dif && str[i + 1] != dif &&
	  str[i + 1] != '\0')
        count++;
      i++;
    }
  return (count);
}

int		len_word(char *str, char dif)
{
  int		len;
  static int	i = 0;

  len = 1;
  i = 0;
  while (str[i] != dif && str[i] != '\0')
    {
      i++;
      len++;
    }
  i++;
  return (len);
}

char	**put_in_tab(char *str, char dif, char **tab)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '\0')
    {
      if (str[i] == dif && str[i + 1] != dif && str[i + 1] != '\0')
	{
	  tab[j++][k] = '\0';
	  k = 0;
	}
      if (str[i] == dif)
	i++;
      tab[j][k++] = str[i++];
    }
  tab[j + 1] = 0;
  return (tab);
}

char	**str_to_wordtab(char *str, char dif)
{
  char	**tab;
  int	len;
  int	i;

  len = nb_word(str, dif);
  tab = xmalloc(sizeof(*tab) * (len + 1));
  i = -1;
  while (++i < len)
    {
      tab[i] = xmalloc(sizeof(tab) * (strlen(str) + 1));
      tab[i] = xmemset(tab[i], '\0', (strlen(str) + 1));
    }
  tab = put_in_tab(str, dif, tab);
  return (tab);
}
