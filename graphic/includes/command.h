/*
** command.h for command in /u/all/veau-g_a/cu/rendu/c/zappy2010/graphic
** 
** Made by adrien veau-greiner
** Login   <veau-g_a@epitech.net>
** 
** Started on  Thu May 13 23:08:35 2010 adrien veau-greiner
** Last update Wed Jun  9 15:46:54 2010 adrien veau-greiner
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
# define CMD_PNW	"pnw" 
# define CMD_PPO	"ppo"
# define CMD_PLV	"plv"
# define CMD_PIN	"pin"
# define CMD_PEX	"pex"
# define CMD_PBC	"pbc"
# define CMD_PIC	"pic"
# define CMD_PIE	"pie"
# define CMD_PFK	"pfk"
# define CMD_PDR	"pdr"
# define CMD_PGT	"pgt"
# define CMD_PDI	"pdi"
# define CMD_ENW	"enw"
# define CMD_EHT	"eht"
# define CMD_EBO	"ebo"
# define CMD_EDI	"edi"
# define CMD_SEG	"seg"
# define CMD_SMG	"smg"
# define CMD_SUC	"suc"
# define CMD_SBP	"sbp"

/* --- Ctructure --- */
typedef struct	s_command
{
  char		*cmd_name;
  int		(*f)(char **param, t_client *cl);
}		t_cmd;

/* Tableau de pointeurs sur fonction */
t_cmd		cmd_tab[26] = {
  {WELCOME, cmd_init},
  {CMD_BCT, cmd_bct},
  {CMD_TNA, cmd_tna},
  {CMD_MSZ, cmd_msz},
  {CMD_SGT, cmd_sgt},
  {CMD_PNW, cmd_pnw},
  {CMD_PPO, cmd_ppo},
  {CMD_PLV, cmd_plv},
  {CMD_PIN, cmd_pin},
  {CMD_PEX, cmd_pex},
  {CMD_PBC, cmd_pbc},
  {CMD_PIC, cmd_pic},
  {CMD_PIE, cmd_pie},
  {CMD_PFK, cmd_pfk},
  {CMD_PDR, cmd_pdr},
  {CMD_PGT, cmd_pgt},
  {CMD_PDI, cmd_pdi},
  {CMD_ENW, cmd_enw},
  {CMD_EHT, cmd_eht},
  {CMD_EBO, cmd_ebo},
  {CMD_EDI, cmd_edi},
  {CMD_SEG, cmd_seg},
  {CMD_SMG, cmd_smg},
  {CMD_SUC, cmd_suc},
  {CMD_SBP, cmd_sbp},
  {0, 0},
};

#endif
