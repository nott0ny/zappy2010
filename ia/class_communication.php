<?php
// class_communication.php for Class Communication in /u/all/luquet_t/cu/Desktop/zappy2010/ia
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Thu May 13 13:57:54 2010 thomas luquet
// Last update Thu May 13 19:47:37 2010 thomas luquet
//

class		Communication
{
  private	$sock;
  private	$port;
  protected	$host;

  public	function	__construct()
  {

  }

  public	function	set_host($host)
  {
    $this->host = $host;
  }
  public	function	set_port($port)
  {
    $this->port = $port;
  }

  public	function	send_msg($msg)
  {
    if (socket_write($this->sock, trim($msg)."\n", strlen($msg)+1) == FALSE)
      aff_error("SEND MESSAGE FAIL -> Socket :".$this->sock."MESSAGE : ".$msg);
    else
      aff_server_send($msg); //c 'est bouen
  }

  public	function	receive_msg()
  {
    $rep = trim(socket_read($this->sock, 1024, PHP_NORMAL_READ));

    if ($rep == FALSE)
      aff_error("RECEIVE MSG FAIL ->".socket_last_error()."<- Socket: ".$this->socket);
    else if ($rep == "")
      {
	// tu recoi rien => tu fait rien... Ou pas...

      }
    else
      {
	aff_server_receive($rep);
	//fonction de traitement des messages
	return($rep);
      }
  }

  public	function	disconnect()
  {
    if (@socket_shutdown($this->sock, 2) == FALSE)
      return (aff_error(socket_strerror(socket_last_error())));
    socket_close($this->sock);
    aff_ok("Closing connection client ".$this->id." on server : ".$this->host.":"
	   .$this->port." succeed.");
  }


  public function	connect()
  {

    $temp = $this->host;

    if (($this->host = gethostbyname($this->host)) == $temp)
	return (aff_error("Unknown host !!!"));
    if (($this->sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) == FALSE)
      return (aff_error(socket_strerror(socket_last_error())));
    if (socket_set_option($this->sock, SOL_SOCKET, SO_REUSEADDR, 1) == FALSE)
       return (aff_error("set option to socket failed !!!"));
    if (socket_connect($this->sock, $this->host, $this->port) == FALSE)
      return (aff_error(socket_strerror(socket_last_error())));
    aff_ok("Connecting client ".$this->id." on server ".$this->host.":"
	   .$this->port." succeed.");
    return (TRUE);
  }

  /*
  public	function	init_comm_server()
  {
    //    aff_ok(socket_read($server, 9, PHP_NORMAL_READ));
    socket_write($server, "thor42", 6);
    aff_ok(socket_read($server, 1, PHP_NORMAL_READ));
    aff_ok(socket_read($server, 8, PHP_NORMAL_READ));

  }
*/


}

?>