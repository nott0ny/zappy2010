<?php
// couleur.php for couleur in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:07:45 2009 thomas luquet
// Last update Tue May  4 21:32:16 2010 thomas luquet
//


function        vert($truc)
{
  return ("\33[32m".$truc."\33[0m");
}

function        bleu($truc)
{
  return("\33[34m".$truc."\33[0m");
}

function        rouge($truc)
{
  return("\33[31m".$truc."\33[0m");
}

function        yellow($truc)
{
  return("\33[33m".$truc."\33[0m");
}

function        magenta($truc)
{
  return("\33[45m".$truc."\33[0m");
}
function        cyan($truc)
{
  return("\33[36m".$truc."\33[0m");
}
?>