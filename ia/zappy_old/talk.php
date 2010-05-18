<?php
// talk.php for talk in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:00:56 2009 thomas luquet
// Last update Mon Jun 22 15:40:08 2009 thomas luquet
//

function	send_repeat($glob)
{
  send_msg_to_serv($glob, $glob['repeat']);
  return($glob);
}

function	send_hello($glob)
{
  $glob = talk($glob, 'hello :-)');
  return($glob);
}

?>