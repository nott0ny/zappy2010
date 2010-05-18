<?php
// go.php for go bouff in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:07:28 2009 thomas luquet
// Last update Mon Jun 22 14:07:31 2009 thomas luquet
//


function	b_go_bouf($glob)
{
  /*
   1 cherche le plus cours chemi
   2 Build path vers bouf
  */


  $case_to_go = find_shorter_way($glob['vision'], "nourriture", $glob['lvl']);

  if ($case_to_go > 0)
    {
      // on vas chercher le chemin pour aller manger
      $glob = build_way_to_go($glob, $case_to_go, "b_go_bouf");
      return ($glob);
    }
  else if ($case_to_go == 0)
    { //On est sur la bonne case
      aff_client("Il y  a de la nourriture sur ma case !");
      return ($glob);
    }
  else
    {
      $glob = error_to_go($glob, 'b_bouff_20');// il n y a pas de bouf sur la case
      return($glob);
    }
  aff_error_code("Out of go bouf");
}

function	caseplvl($lvl)
{
  $ans = 4;
  while ($lvl != 1)
    {
      $ans += $ans + 2;
      $lvl--;
    }
  return ($ans);
}

function	find_shorter_way($vision, $obj, $lvl)
{
  $max = caseplvl($lvl);
  //  test("max: ".$max);

  for($i=0; $i < $max; $i++)
    {
      if (strstr($vision[$i], $obj) == TRUE)
	return ($i);
    }
  return (-1);
}

?>
