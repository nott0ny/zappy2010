<?php
// go_stone.php for zappy  in /u/all/luquet_t/cu/Desktop/zappy/ia
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Wed Jun 17 22:45:06 2009 thomas luquet
// Last update Sat Jun 20 22:11:38 2009 thomas luquet
//

function	b_go_linemate($glob)
{
  $case_to_go = find_shorter_way($glob['vision'], "linemate", $glob['lvl']);

  if ($case_to_go > 0)
    {
      $glob = build_way_to_go($glob, $case_to_go, "b_go_linemate");
      return ($glob);
    }
  else if ($case_to_go == 0)
      return ($glob);
  else
    {
      $glob = error_to_go($glob, 'b_sg_linemate');// il n y a pas de bouf sur la case
      return($glob);
    }
  aff_error_code("Out of go stone");
}

function	b_go_deraumere($glob)
{
  $case_to_go = find_shorter_way($glob['vision'], "deraumere", $glob['lvl']);
  if ($case_to_go > 0)
    {
      $glob = build_way_to_go($glob, $case_to_go, "b_go_deraumere");
      return ($glob);
    }
  else if ($case_to_go == 0)
      return ($glob);
  else
    {
      $glob = error_to_go($glob, 'b_sg_deraumere');// il n y a pas de bouf sur la case
      return($glob);
    }
  aff_error_code("Out of go stone");
}


function	b_go_sibur($glob)
{
  $case_to_go = find_shorter_way($glob['vision'], "sibur", $glob['lvl']);
  if ($case_to_go > 0)
    {
      $glob = build_way_to_go($glob, $case_to_go, "b_go_sibur");
      return ($glob);
    }
  else if ($case_to_go == 0)
      return ($glob);
  else
    {
      $glob = error_to_go($glob, 'b_sg_sibur');
      return($glob);
    }
  aff_error_code("Out of go stone");
}


?>