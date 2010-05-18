<?php
// enter_the_game.php for enter_the_game in /u/all/veau-g_a/cu/rendu/c/zappy2010/ia
// 
// Made by adrien veau-greiner
// Login   <veau-g_a@epitech.net>
// 
// Started on  Thu May 13 11:12:28 2010 adrien veau-greiner
// Last update Thu May 13 18:51:47 2010 thomas luquet
//

function	enter_the_game($player)
{
  if ($player->connect() == TRUE)
    {

      if ($player->receive_msg() == "BIENVENUE"); // il recoit le Welcome
      {
	$player->send_msg($player->team_name); //envoi du nom de team
	$player->receive_msg();
      }
      aff_error("Je ne recois pas le BIENVENUE");
      return ;
    }
  else
    aff_error("Connection FAIL");
  $player->disconnect();
}

?>