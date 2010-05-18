<?php
// work.php for metier in /u/all/luquet_t/public/ia
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Fri Jun 19 05:31:40 2009 thomas luquet
// Last update Mon Jun 22 23:30:35 2009 thomas luquet
//



function	work_forker($glob)
{
  $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_bouff_20"));
  $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_fork"));
  return($glob);
}

function	work_for_lvl2($glob)
{
  $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_lvl2"));
  return($glob);
}

function	work_for_lvl3($glob)
{
  test("Job lvl 3");
  $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_lvl3"));
  return($glob);
}

function	first_work($glob)
{
  aff_client("first work OK");
  $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_bouff_20"));
  $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_hello"));
  $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_fork"));
  return($glob);
}


function	new_job($glob)
{
  if ($glob['list_action'][0]['done'] ==0)
    $glob = first_work($glob);
  else if ($glob['nb_pote'] >= 2 && $glob['lvl'] == 2)
    $glob = work_for_lvl3($glob);
  else if ($glob['nb_pote']  > 1 && $glob['lvl'] == 1)
    $glob = work_for_lvl2($glob);
  else if ($glob['nb_pote'] == 0 && $glob['lvl'] == 1
      && count($glob['time_to_fork']) > 1
      && count($glob['time_to_fork']) < 3)
    $glob = work_forker($glob);
  else
    $glob['list_action'] = add_action_place($glob['list_action'], name_to_arr("b_rand"));

  $glob = update_actions($glob);
  return($glob);
}


function	check_job($glob)
{

  $glob['total_action'] = count($glob['list_action']);
  $c = count($glob['list_action']);

  for ($i =0, $d++; $glob['list_action'][$i]['done'] == 1; $i++)
    $d++;

  if ($d == $c)
    {
      $glob = new_job($glob);
    }
  else if ($glob['list_action'][$c]['done'] == 1 ||
	   $glob['list_action'][$c -1]['done'] == 1
	   )
    {
      $name_last = name_awaiting_ans($glob);
      if (substr($name_last, 0, 2) != "b_")
	{
	  test("new ?");
	  $glob = new_job($glob);
	}
    }

  return($glob);
}


?>