<?php
// do_action.php for do action in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 23:22:42 2009 thomas luquet
// Last update Mon Jun 22 23:22:44 2009 thomas luquet
//



function	do_action($glob)
{
  for ($i = 0; $glob['list_action'][$i]; $i++)
    {
      if ($glob['list_action'][$i]['done'] == 0)
	{
	  $action_name = $glob['list_action'][$i]['nom_action'];

	  if (substr($action_name, 0, 2 ) == "b_")
	    {
	      $glob['list_action'][$i]['done'] = 1;
	      $glob['list_action'][$i]['waiting_answer'] = 1;

	      $glob = call_user_func($action_name, $glob);
	      $glob['big'] = 1;
	      $glob = update_actions($glob);
	      return($glob);
	    }
	  else
	    {
	      $glob['list_action'][$i]['done'] = 1;
	      $glob['list_action'][$i]['waiting_answer'] = 0;
	      $glob = call_user_func($action_name, $glob);
	      $glob['big'] = 0;
	      $glob = update_actions($glob);
	      return($glob);
	    }
	}
    }

  print_r($glob);
  test("action end ".$glob['total_action']);
  // Devrait jamais arrive la
  aff_error_code("end done");
  return($glob);
}



?>