<?php
// update_info.php for update info in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:01:11 2009 thomas luquet
// Last update Mon Jun 22 18:59:32 2009 thomas luquet
//


function	update_voir($glob, $line)
{
  $glob= set_last_waiting_ans($glob, "voir", "ok");
  $glob['vision'] = explode(',', $line);
  return ($glob);
}

function	update_inventaire($glob, $line)
{
  $glob = set_last_waiting_ans($glob, "inventaire", "ok");
  $line = no_acolade($line);
  $glob['inventaire'] = explode(',', $line);
  for ($i =0; $glob['inventaire'][$i]; $i++)
    if (strstr($glob['inventaire'][$i], 'nourriture') == TRUE)
	{
	  $nb = explode(" ", $glob['inventaire'][$i]);
	  $glob['bouff_c'] = $nb[1]*126;
	}
  return($glob);
}

function	voir($glob)
{
  send_msg_to_serv($glob, "voir");
  return($glob);
}

function	inventaire($glob)
{
  send_msg_to_serv($glob, "inventaire");
  return($glob);
}



?>