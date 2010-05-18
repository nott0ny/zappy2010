<?php
// action_spe.php for action special zappy in /u/all/luquet_t/public/ia
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Fri Jun 19 05:22:09 2009 thomas luquet
// Last update Mon Jun 22 20:44:05 2009 thomas luquet
//


function	get_nourriture($glob)
{
  send_msg_to_serv($glob, "prend nourriture");
  $glob['bouff_c'] += 126;
  return($glob);
}

function	send_fork($glob)
{
  send_msg_to_serv($glob, "fork");

  return($glob);
}


function	incantation($glob)
{
  send_msg_to_serv($glob, "incantation");
  return($glob);
}





?>