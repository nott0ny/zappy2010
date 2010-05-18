<?php
// message.php for message in /u/all/veau-g_a/cu/rendu/c/zappy2010/ia
// 
// Made by adrien veau-greiner
// Login   <veau-g_a@epitech.net>
// 
// Started on  Thu May 13 11:12:48 2010 adrien veau-greiner
// Last update Thu May 13 18:46:58 2010 thomas luquet
//

  /**/


function	aff_help()
{
  echo "Usage: client [-p port] [-n team name] [-h host (default:localhost)]\n";
}

function	aff_ok($str)
{
  //  printf("%s", vert($str."\n"));
  echo vert($str."\n");
  return(TRUE);
}

function	aff_error($str)
{
  // fprintf(STDERR, "%", rouge("Error : ".$str."\n"));
  echo  rouge("\n\n[ERROR] ".$str."\n");
  exit;
  return (FALSE);
}



function	aff_server_send($str)
{
  //  printf("%s", vert($str."\n"));
  echo bleu("Envoit : \"".$str."\" -> SERVER\n");
  return(TRUE);
}

function	aff_server_receive($str)
{
  //  printf("%s", vert($str."\n"));
  echo cyan("Recoit : \"".$str."\"\n");
  return(TRUE);
}

function	aff_debug($str)
{
  //  printf("%s", yellow($str."\n"));
  echo yellow($str."\n");
  return(TRUE);
}

?>