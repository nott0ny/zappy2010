<?php
// aff_message.php for disp mess in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 13:35:18 2009 thomas luquet
// Last update Mon Jun 22 23:12:17 2009 thomas luquet
//


function	aff_serveur($str)
{
  echo bleu("[Serveur : ] ").$str.bleu(" [/Serveur]\n");
}


function	aff_client($str, $glob = 0)
{
  if ($glob == 0)
    echo vert("[Client : ] ").$str."\n";
  else
    echo vert("Client [lvl:").cyan($glob["lvl"]).vert("] =>").$str."\n";
}

function	test($str)
{
  echo yellow("-->".$str."<--\n");
}
function	aff_error_code($str)
{
  echo rouge("[ : ERROR Code ! : ]").$str.rouge("[ : ERROR !]")."\n";
  exit;
}

function	aff_error_connect($str)
{
  echo rouge("[ : ERROR ! : ]").$str.rouge("[ : ERROR !]")."\n";
  echo rouge("-> exit\n");
  exit;
  return(-1);
}



?>