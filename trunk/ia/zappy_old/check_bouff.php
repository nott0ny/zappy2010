<?php
// check_bouff.php for check bouff in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Sat Jun 20 20:43:37 2009 thomas luquet
// Last update Sat Jun 20 21:30:39 2009 thomas luquet
//


function	check_bouff($glob)
{
  if ($glob['bouff_c'] < 130)
    {
      $place_to_add = find_action_where_add($glob, $rempl);
      $arr = array(
		   name_to_arr("b_bouff_20"),
		   name_to_arr("b_bouff_20"),
		   name_to_arr("b_bouff_20")
		   );
      $glob['list_action'] = add_action_place($glob['list_action'], $arr, $place_to_add);
    }
  return($glob);
}


/*
1 unite = 126 / t
*/
?>