<?php
// pars_cmd.php for pars in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 13:34:56 2009 thomas luquet
// Last update Mon Jun 22 14:41:51 2009 thomas luquet
//


function	init_pars($argv, $glob)
{

  if (count($argv) == 7 && $argv[1] == "-n"
      && $argv[3] == '-p'
      && $argv[5] == '-h')
    {
      $glob['equipe'] = $argv[2];
      $glob['port'] =$argv[4];
      $glob['host'] =$argv[6];
      return($glob);
    }
  else
    {
      aff_error_code("usage : ./client.php -n nom -p port -h host");
      exit;
    }


}


?>