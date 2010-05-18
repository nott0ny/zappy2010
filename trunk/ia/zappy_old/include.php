<?php
// include.php for include in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 13:35:26 2009 thomas luquet
// Last update Mon Jun 22 14:39:24 2009 thomas luquet
//

  /*
   Structure
  */

include("global.php");
include("pars_cmd.php");
/*
 Protocole
*/
include("xconnect.php");
include("send_msg.php");

/*
 goodies kikoo-lol
*/
include("couleur.php");
include("aff_message.php");
include("death.php");
include("lvl_up.php");
include("art_lvl.php");

/*
 Gestion des listes d actions
*/
include("intelligence.php");
include("build_action.php");
include("do_action.php");
include("update_info.php");
/*
 Gestion des mouvements
*/
include("go.php");
include("build_way_to_go.php");
include("go_stone.php");

/*
 Gestions des listes d' actions
*/
include("list_way_action.php");
include("tools.php");
include("fork.php");

/*
 Envoit d'action
*/
include("action_spe.php");
include("action_direction.php");
include("action_useless.php");
include("get_stones.php");
include("drop_stones.php");

/*
 Reception des reponses
*/
include("analyse.php");
include("sync.php");
include("update_oko.php");
include("check_bouff.php");

/*
 Communication et gestion des ressources humaines :-)
*/
include("talk.php");
include("broad_cast.php");
include("info_friendz.php");

/*
 Gestion de metie
*/

include("work.php");

?>