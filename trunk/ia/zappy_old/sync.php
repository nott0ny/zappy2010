<?php
// sync.php for sync in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 13:39:51 2009 thomas luquet
// Last update Mon Jun 22 14:00:08 2009 thomas luquet
//

function	name_awaiting_ans($glob)
{
  $i= find_last_waiting_ans($glob);
  return($glob['list_action'][$i]['nom_action']);
}

function	find_last_waiting_ans($glob)
{
  for ($i = 0; $glob['list_action'][$i]; $i++)
    {
      if ( $glob['list_action'][$i]['done'] == 1 &&
	   $glob['list_action'][$i]['waiting_answer'] == 0)
	{
	  break;
	}
    }
  return($i);
}

function	set_last_waiting_ans($glob, $name, $ans)
{
  $last_waiting_ans = find_last_waiting_ans($glob);
  $name_action_await = name_awaiting_ans($glob);
  if ($name == "ok" || $name == "ko")
    $glob = update_oko_ans($glob, $name, $ans);
  else if ($name_action_await == $name)
    {
      if ($name == "inventaire")
	{
	  $glob['time_c'] += 1;
	  $glob['bouff_c']--;
	}
      else if ($name == "incantation")
	{
	  $glob['time_c'] += 300;
	  $glob['bouff_c'] -=300;
	}
      else if ($name == "voir")
	{
	  $glob['time_c'] += + 7;
	  $glob['bouff_c'] -= 7;
	}
      else
	aff_error_code("message recu incomprhenssible: : ".$name);
      $glob['list_action'][$last_waiting_ans]['waiting_answer'] = 1;
    }
  else
    aff_error_code("Decalage entre message serveur attente client");
  return($glob);
}



?>