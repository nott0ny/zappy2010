#!/usr/local/bin/php
<?php
// ia.php for ia in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 13:35:48 2009 thomas luquet
// Last update Mon Jun 22 14:45:45 2009 thomas luquet
//

include("include.php");

function        init_connection($glob)
{
  $glob['fd'] = xfsockopen($glob['host'], $glob['port']);
  if ($glob['fd'])
    aff_client("FD-SOCKET OK");
  else
    {
      aff_error_connect("Connection rate");
      init_connection($glob);
    }
  return($glob);
}

function	init_message($glob)
{
    $line = xfgets($glob);
    if ($line == "BIENVENUE")
      aff_client("Nous sommes connecte");
  send_msg_to_serv($glob, $glob['equipe']);
  $glob['num_client'] = xfgets($glob);
  $arr_map = explode(' ', xfgets($glob));
  $glob['map_x'] = $arr_map[0];
  $glob['map_y'] = $arr_map[1];
  return($glob);
}


$glob = init_pars($argv, $glob);
$glob = init_connection($glob);
$glob = init_message($glob);


while(42)
  {
    $glob = pars_line($glob, $line);


    if ($glob['big'] != 1)
      $line = xfgets($glob);
  }



?>