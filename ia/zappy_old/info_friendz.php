<?php
// info_friendz.php for info friend in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 16:17:13 2009 thomas luquet
// Last update Mon Jun 22 18:21:23 2009 thomas luquet
//


function	update_info_friendz($glob, $info)
{

  for ($i=0, $flag=0; $glob['list_friend'][$i]; $i++)
    {
      if ($glob['list_friend'][$i]['id'] == $info[1])
	$flag=1;
    }
  $glob['nb_pote']=$i;
  if ($flag == 0)
    {
      array_push($glob['list_friend'],
		 array('id'=>$info[1], 'lvl' => $info[4]) );
      $glob['nb_pote']++;
    }

  $glob['msg_c'] = $info[3];

  return($glob);
}



function	b_wait_friend($glob)
{

  test("<-- You Hou, les copines ? -->");
  exit;
  return($glob);
}

?>