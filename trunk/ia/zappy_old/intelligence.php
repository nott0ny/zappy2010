<?php
// intelligence.php for intelligence in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:06:35 2009 thomas luquet
// Last update Mon Jun 22 23:13:33 2009 thomas luquet
//


function	pars_line($glob, $line)
{
  if ($glob['big'] != 1)
    {
      aff_serveur($line);
      //  call_user_func('increment', $a);
      if ($line == "OK" || $line == "KO" || $line == "ok" || $line =="ko")
	$glob = verif_answer($glob, $line);
      else if (substr($line, 0, 2) == "{ ")
	$glob = update_voir($glob, $line);
      else if (substr($line, 0, 1) == "{")
	$glob = update_inventaire($glob, $line);
      else if (substr($line, 0, 7) == "message")
	 $glob = analyze_sound($glob, $line);
      else if (substr($line, 0, 13) == "niveau actuel")
	$glob = niv_act($glob, $line);
      else if (substr($line, 0, 18) == "elevation en cours")
	lvl_en_cour();
      else if (substr($line, 0, 4) == "mort")
	mort($glob);
      else
	aff_serveugr("Message incompris : ".$line);
    }
  $glob = check_job($glob);
  $glob = analyze_situation($glob);
  $glob = do_action($glob); // execut
  return ($glob);
}


?>