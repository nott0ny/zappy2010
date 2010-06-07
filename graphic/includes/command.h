/*
** command.h for command in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:08:35 2010 adrien veau-greiner
** Last update Mon Jun  7 19:03:51 2010 adrien veau-greiner
*/

#ifndef __COMMAND_H__
# define __COMMAND_H__

# include "graphics.h"
# include "client.h"

/* ----- MACRO ----- */
# define WELCOME        "BIENVENUE"
# define CMD_BCT	"bct"
# define CMD_TNA	"tna"
# define CMD_MSZ	"msz"
# define CMD_SGT	"sgt"

/* --- Ctructure --- */
typedef struct	s_command
{
  char		*cmd_name;
  int		(*f)(char **param, t_client *cl);
}		t_cmd;

/* Tableau de pointeurs sur fonction */
t_cmd		cmd_tab[6] = {
  {WELCOME, cmd_init},
  {CMD_BCT, cmd_bct},
  {CMD_TNA, cmd_tna},
  {CMD_MSZ, cmd_msz},
  {CMD_SGT, cmd_sgt},
  {0, 0},
};

#endif
