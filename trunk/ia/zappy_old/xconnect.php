<?php
// xconnect.php for xconnect in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:01:50 2009 thomas luquet
// Last update Mon Jun 22 14:26:27 2009 thomas luquet
//


function        xfgets($glob)
{
  if ($glob['fd'] != FALSE)
    {

      while ($msg = fgets($glob['fd']))
	{

	  if ($msg != FALSE)
	    {
	      $msg = no_back_slash($msg);

	      return($msg);
	    }
	  else
	    aff_error_connect("Error Fgets 1");
	}
      aff_error_connect("Error Fgets 2");
    }
  else
    aff_error_connect("Pas de FD dans glob");

}

function        xfsockopen($address, $port)
{


  $fd = fsockopen($address, $port, &$erno, &$errstr, 10);
  if ($fd)
    return($fd);
  else
    aff_error_connect("Error Socket Open (".$erno.") => ".$errstr."\n");
}
function	xfclose($glob)
{
  if (fclose($glob['fd']) != FALSE)
    return(1);
  else
    aff_error_connect("echeque du close");

}


?>