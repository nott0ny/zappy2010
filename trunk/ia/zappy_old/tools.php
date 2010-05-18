<?php
// tools.php for tools in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:01:25 2009 thomas luquet
// Last update Mon Jun 22 19:02:09 2009 thomas luquet
//


function	no_back_slash($str)
{
    $str = substr($str, 0, -1);
  //  echo "--".$str."--";
  return($str);
}

function	no_acolade($str)
{
  //enleve le 1er et le dernier param
  $str = substr($str, 0, -1);
  $str = substr($str, 1);
  return($str);
}

function	name_to_arr($name)
{
$arr=  array(
	"nom_action" => $name,
	"priorite" => 0,
	"waiting_answer" => 0,
	"pb" => 0,
	"order" => 0,
	"done"=>0
	);
  return($arr);
}
?>