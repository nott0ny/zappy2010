<?php
// send_msg.php for send msg in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:02:07 2009 thomas luquet
// Last update Mon Jun 22 15:47:14 2009 thomas luquet
//


function	send_msg_to_serv($glob, $msg)
{
  aff_client($msg, $glob);

  $res = fputs($glob['fd'], $msg."\n");


  if ($res != FALSE)
    return ($msg);
  else
    {
      aff_error_connect("MSG :".$msg." Not Send !");
      return(-1);
    }
}


?>