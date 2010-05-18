<?php
// list_way_action.php for list action in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:03:28 2009 thomas luquet
// Last update Mon Jun 22 23:23:42 2009 thomas luquet
//

function	give_action()
{
  $arr_action =
    array(
	  array ("nom" =>"b_fork",
		 "actions"=> array('b_bouff_20', 'send_fork' )),
	  array("nom"=>	"b_bouff_20",
		"actions" => array('voir', 'b_go_bouf', 'get_nourriture')),
	  array ("nom" =>"b_hello",
		 "actions"=> array('send_hello')),
	  array ("nom" =>"b_sg_linemate",
		 "actions"=> array('voir', 'b_go_linemate')),
	  array ("nom" =>"b_sg_deraumere",
		 "actions"=> array('voir', 'b_go_deraumere')),
	  array ("nom" =>"b_sg_sibur",
		 "actions"=> array('voir', 'b_go_sibur')),
	  );
  $to_add_rand_action = list_rand_action();
  $to_add_dep = list_deplacement();
  $to_add_lvl = list_lvl();
  $arr_action = array_merge($arr_action, $to_add_dep, $to_add_lvl, $to_add_rand_action);
  //  print_r($arr_action);
  return($arr_action);
}

function	list_rand_action()
{
  $arr_item = array('b_go_bouf', 'inventaire', 'b_sg_linemate');
  $i = rand(0, 3);
  $arr_action = array(
		      array ("nom" =>"b_rand",
			     "actions"=> array($arr_item[$i])
			     )
		      );

  return($arr_action);
}

function	list_lvl()
{
  $arr = array(
	       array("nom"=>	"b_lvl2",
		     "actions" => array('voir', 'b_sg_linemate', 'incantation')
		     ),
	       array("nom"=>	"b_lvl3",
		     "actions" => array('voir', 'b_go_linemate',
					'get_linemate',
					'b_go_deraumere',
					'get_deraumere',
					'b_go_sibur',
					'get_deraumere',
					'b_go_sibur',
					'get_sibur',
					'drop_linemate',
					'drop_deraumere',
					'drop_sibur',
					'b_wait_friend',
					'incantation')
		     ),
	       );
  return($arr);
}

function	list_deplacement()
{
  $arr =  array(
		array("nom"=>	"b_case1",
		      "actions" => array('avance', 'gauche')),
		array("nom"=>	"b_case2",
		      "actions" => array('avance')),
		array("nom"=>	"b_case3",
		      "actions" => array('droite', 'avance')),
		array("nom"=>	"b_case4",
		      "actions" => array('avance', 'avance', 'gauche', 'gauche')),
		array("nom"=>	"b_case5",
		      "actions" => array('avance', 'avance', 'gauche' )),
		array("nom"=>	"b_case6",
		      "actions" => array('avance', 'avance' )),
		array("nom"=>	"b_case7",
		      "actions" => array('avance', 'avance', 'droite')),
		array("nom"=>	"b_case8",
		      "actions" => array('avance', 'avance', 'droite', 'droite'))
		);
  return($arr);
}






?>