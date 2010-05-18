<?php
// analyse.php for analyze in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:10:00 2009 thomas luquet
// Last update Mon Jun 22 19:20:13 2009 thomas luquet
//


function	verif_answer($glob, $line)
{
  if ($line == "OK" || $line == "ok")
    $glob = set_last_waiting_ans($glob, $line, "ok");
  else if($line == "KO" || $line =="ko" )
    $glob = set_last_waiting_ans($glob, $line, "ko");
  return($glob);
}

function	analyze_situation($glob)
{
  /*
   Verifie notamment si erreur ou si chgt de situation
   Verifier la bouffe ...
   fait les chgt de priorite
  */

  $glob = check_bouff($glob);


  for ($i=0; $glob['list_action'][$i]['pb'] > 0; $i++)
    {
      test("Y a un pb !");
      // on remet ca ?
    }
  for ($i=0; $glob['time_to_fork'][$i]; $i++)
    {
      if (($glob['time_c'] > $glob['time_to_fork'][$i]['next'])
	  &&  ($glob['time_to_fork'][$i]["done"] == 0)
	  && ($glob['time_to_fork'][$i]["next"] != 0)
	  )
	{
	  $glob = call_my_egg($glob, $i);
	}
    }

  return($glob);
}

?>