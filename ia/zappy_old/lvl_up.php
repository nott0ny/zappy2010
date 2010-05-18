<?php
// lvl_up.php for lvl up in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:01:36 2009 thomas luquet
// Last update Mon Jun 22 14:01:40 2009 thomas luquet
//


function	niv_act($glob, $line)
{

  $glob = set_last_waiting_ans($glob, "incantation", "ok" );
  $glob['lvl'] = substr($line, 16, 1);
  art_lvl($glob['lvl']);


  return($glob);
}


function	lvl_en_cour()
{
  echo yellow("	Elevation en cours...
                __
             __/_ \__
            / ___\ \ \
            \/ /  \/ /
            / /\__/_/\
            \_\ \____/
               \__/

");

}
?>