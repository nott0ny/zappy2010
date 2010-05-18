<?php
// action_direction.php for action direction in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:09:37 2009 thomas luquet
// Last update Mon Jun 22 14:09:41 2009 thomas luquet
//



function	gauche($glob)
{
  send_msg_to_serv($glob, "gauche");
  return($glob);
}
function	droite($glob)
{
  send_msg_to_serv($glob, "droite");
  return($glob);
}

function	avance($glob)
{
  send_msg_to_serv($glob, "avance");
  return($glob);
}

?>