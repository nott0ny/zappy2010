/*
** utils.c for utils in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 22:33:43 2010 adrien veau-greiner
** Last update Thu Jun 10 11:48:17 2010 adrien veau-greiner
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "client.h"

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  if (str1 == 0 && str2 == 0)
    return (0);
  if (str1 == 0)
    return (str2);
  if (str2 == 0)
    return (str1);
  j = strlen(str1) + strlen(str2) + 1;
  str = xmalloc(sizeof(*str) * j);
  while (str1[i] != '\0')
    {
      str[i] = str1[i];
      ++i;
    }
  j = 0;
  while (str2[j] != '\0')
    str[i++] = str2[j++];
  str[i] = '\0';
  return (str);
}

int	str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!((str[i] >= '0') && (str[i] <= '9')))
	return (0);
      i++;
    }
  return (1);
}

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int	tab_int_len(int *tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void aff_int_tab(int *tab)
{
  int i;

  i = 0;
  while (tab[i])
    printf("%d ,", tab[i++]);
}

void aff_tab(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    printf("%s ", tab[i++]);
  printf("\n");
}
