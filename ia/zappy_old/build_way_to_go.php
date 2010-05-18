#!/usr/local/bin/php
<?php
// build_way_to_go.php for build go in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 13:36:43 2009 thomas luquet
// Last update Mon Jun 22 15:01:16 2009 thomas luquet
//


function	build_way_to_go($glob, $case_to_go, $reason_to_go)
{
  $name_act_dir = "b_case".$case_to_go;
  $place_to_add = find_action_where_add($glob, $reason_to_go);
  $arr = array( name_to_arr($name_act_dir));
  $glob['list_action'] = add_action_place($glob['list_action'], $arr, $place_to_add);
  return($glob);
}

function	error_to_go($glob, $obj)
{

  aff_client("Pas de ".$obj." devant moi, je pars en chercher");

  if ($obj == 'b_bouff_20')
    $rempl = 'b_go_bouf';
  else if (strstr($obj, '_sg_') == TRUE)
    $rempl = 'b_go_'.substr($obj, 5);
  else
    $rempl = $obj;

  $place_to_add = find_action_where_add($glob, $rempl);
  $arr = array(
	       name_to_arr(rand_way()),
	       name_to_arr($obj)
	       );
  $glob['list_action'] =
    add_action_place($glob['list_action'], $arr, $place_to_add);
  return($glob);
}

function	rand_way()
{
  $ans = array('droite', 'gauche', 'avance', 'avance', 'avance', 'avance');
  $i= rand(0, 5);
  return($ans[$i]);
}

?>