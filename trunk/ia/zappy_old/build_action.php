<?php
// build_action.php for build action in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 13:37:27 2009 thomas luquet
// Last update Mon Jun 22 15:08:12 2009 thomas luquet
//


function	add_action_place($way_list_action, $arr_action_add, $place = 0)
{
  $arr_deb = array();
  $arr_end = array();
  $arr_finale= array();

  if ($place == 0)
    {
      array_push($way_list_action, $arr_action_add);
      $cur_list_action = update_order($cur_list_action);
      return ($way_list_action);
    }
  else
    {
      $arr_deb = array_slice($way_list_action, 0, $place);
      $arr_end = array_slice($way_list_action, $place+1);
      for ($i=0; $arr_deb[$i]; $i++)
	array_push($arr_finale, $arr_deb[$i]);
      for($i=0; $arr_action_add[$i]; $i++)
	array_push($arr_finale, $arr_action_add[$i]);
      for ($i=0; $arr_end[$i]; $i++)
	array_push($arr_finale, $arr_end[$i]);
      $cur_list_action = update_order($cur_list_action);
      return($arr_finale);
    }
  aff_error_code("end add action");
}


function	update_actions($glob)
{
  $arr_action = give_action();
  $cur_list_action = $glob['list_action'];
  $arr_action_add = array();
  $arr_tmp= array();

  for ($i=0, $flag=0; $cur_list_action[$i]; $i++)
    {
      for ($j=0; $arr_action[$j]; $j++)
	{
	if (substr($cur_list_action[$i]['nom_action'], 0, 2 ) == "b_")
	  if ($cur_list_action[$i]['done'] == 0)
	    if ($cur_list_action[$i]['nom_action'] == $arr_action[$j]['nom'])
	      if ($flag == 0)
		{
		  for ($k=0; $arr_action[$j]['actions'][$k]; $k++)
		    {
		      array_push($arr_action_add, name_to_arr($arr_action[$j]['actions'][$k]));
		      $arr_tmp = array();
		    }
		  $cur_list_action = add_action_place($cur_list_action, $arr_action_add, $i);
		  $arr_action_add = array();
		  $flag = 1;
		}
	}
    }
  $cur_list_action = update_order($cur_list_action);
  $glob['list_action'] = $cur_list_action;
  return($glob);
}

function	update_order($way_list_action)
{
  for ($i=0; $way_list_action[$i]; $i++)
    {
      $way_list_action[$i]['order'] = $i;
    }
  return($way_list_action);
}


function	find_action_where_add($glob, $name_action)
{
  /*
   Trouve l'endroit ou je dois ajouter ce que je dois ajouter
  */
  $cur_list_action = $glob['list_action'];
  for ($i=0; $cur_list_action[$i]; $i++)
    {
      if (($cur_list_action[$i]['nom_action'] == $name_action)
	  && ($cur_list_action[$i]['done'] == 1)
	  && ($cur_list_action[$i + 1]['done'] == 0)
	  )
	return($i);
    }

  //  print_r($glob['list_action']);
  test("La c la merde : name action : ".$name_action."-");
  aff_error_code("A pas trouve ou add l action dans la liste  ");

  return($i);
}




?>