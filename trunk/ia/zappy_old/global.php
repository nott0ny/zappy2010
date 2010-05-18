<?php
// global.php for globale php in /u/all/luquet_t/cu/Desktop/zappy/ia
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Thu Jun 18 20:19:21 2009 thomas luquet
// Last update Mon Jun 22 20:43:43 2009 thomas luquet
//

$glob = array(
	      "lvl" => 1,
	      "id_f" => rand(1, 8225*8225),
	      "del" => ',\,|+/4*2\,-\n|\\',
	      "bouff_c" => 1260,
	      "msg_c" => 0,
	      "time_c" => 0,
	      "time_to_fork" => array(
				      array("next" => 0, "done"=> 0)
				      ),
	      "big" => 1,
	      "nb_pote" => 0,
	      "list_friend"=>array(
				   array("id" =>  0, "lvl"=> 0)
				   ),
	      "list_action" => array(
				     array("nom_action" => "b_vide",
					   "priorite" => 0,
					   "waiting_answer" => 0,
					   "pb" => 0,
					   "order" => 0,
					   "done" => 0
					   )
				     ),
	      );




?>