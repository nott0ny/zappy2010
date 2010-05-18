<?php
// update_oko.php for update ok ou ko in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:02:41 2009 thomas luquet
// Last update Mon Jun 22 14:03:02 2009 thomas luquet
//


function	update_oko_ans($glob, $name, $ans)
{
  $last_waiting_ans = find_last_waiting_ans($glob);
  if ($name == "ok")
    {
      $glob['list_action'][$last_waiting_ans]['waiting_answer'] = 1;
      $glob['time_c'] += 7;
      $glob['bouff_c'] -= 7;
      if ($glob['list_action'][$last_waiting_ans]['nom_action']=='send_fork')
	{
	  $glob['time_c'] += 35;
	  $glob['bouff_c'] -= 35;
	  $arr_f = array("next" => $glob['time_c'] + 601, "done" => 0) ;
	  array_push($glob['time_to_fork'], $arr_f);
	}
    }
  else if ($name == "ko")
    {
      $glob['list_action'][$last_waiting_ans]['waiting_answer']=2;
      $glob['list_action'][$last_waiting_ans]['pb']=1;
      $glob['time_c'] += 7;
      $glob['bouff_c'] -=  7;
      if ($glob['list_action'][$last_waiting_ans]['nom_action']=='send_fork')
	{
	  $glob['time_c'] += 35;
	  $glob['bouff_c'] -= 35;
	}
    }
  else
    aff_error_code("reponse impossible");
  return($glob);
}


?>