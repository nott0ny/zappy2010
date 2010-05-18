<?php
// broad_cast.php for broad cast in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:08:38 2009 thomas luquet
// Last update Mon Jun 22 18:21:36 2009 thomas luquet
//

function	analyze_sound($glob, $line)
{
  $message = substr($line, 10);
  $dir = substr($libe, 8, 1);

  if ( try_decript($glob, $message) == -42)
    {
      //message inerne
      aff_client("Message interne ressus !");
      $glob = dekrypte($glob, $message);
    }
  else
    {
    // message ennemie
      aff_client("message ennemies ! Need Repeat :-P");
      $glob = launch_repeat($glob, $message);
    }
  return($glob);
}


function	dekrypte($glob, $message)
{
  $info = explode($glob['del'], $message);
  $glob = update_info_friendz($glob, $info);
  if ($info[6] == 'hello :-)')
    aff_client("Salut mec, soit le bienvenue !");
  return($glob);
}

function	try_decript($glob, $message)
{
  $rep = explode($glob['del'], $message);
  if ((count($rep) == 8) && ($rep[1] != $glob['equipe'] ))
    return(-42);
  return(1);
}

function	talk($glob, $mess, $destinatair = 0)
{
  if ($destinatair == 0)
    $destinatair ='all';

  $glob['msg_c']++;

  $line =
    $glob['del'].$glob['id_f'].
    $glob['del'].$glob['equipe'].
    $glob['del'].$glob['msg_c'].
    $glob['del'].$glob['lvl'].
    $glob['del'].$destinatair.
    $glob['del'].$mess.
    $glob['del'];

  $line = 'broadcast '.$line;
  send_msg_to_serv($glob, $line);
  return($glob);
}

function	launch_repeat($glob, $str)
{
  $randou = rand(0, 3);
  if ($randou == 1)
    {
      $place_to_add = find_action_where_add($glob, $rempl);
      $arr = array(
		   name_to_arr('send_repeat')
		   );
      $glob['list_action'] =
	add_action_place($glob['list_action'], $arr, $place_to_add);
      $glob['repeat'] = $str;
      return($glob);
    }
}

?>