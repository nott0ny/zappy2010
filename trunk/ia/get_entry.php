<?php
// get_entry.php for get_entry in /u/all/veau-g_a/cu/rendu/c/zappy2010/ia
// 
// Made by adrien veau-greiner
// Login   <veau-g_a@epitech.net>
// 
// Started on  Thu May  6 15:18:58 2010 adrien veau-greiner
// Last update Fri May  7 11:07:16 2010 adrien veau-greiner
//

function	get_team_name($arg)
{
  if ($arg == "GRAPHIC" || $arg == "graphic")
    {
      aff_error("name \"GRAPHIC\" or \"graphic\" is reserved !!!");
      return (-1);
    }
  if ($arg == "-p" || $arg == "-n" || $arg == "-h")
    return (-1);
  return ($arg);
}

function	get_port($arg)
{
  if ($arg == "-p" || $arg == "-n" || $arg == "-h")
    return (-1);
  if ((is_numeric($arg) == FALSE) || ($argv > 65535))
    {
      aff_error("port ".$arg." is not a valid port !!!");
      return (-1);
    }
  return ($arg);
}

function	get_host($arg)
{
  if ($arg == "-p" || $arg == "-n" || $arg == "-h")
    return (-1);
  return ($arg);
}

function	get_args($argv, $port, $team, $host)
{
  $i = 0;
  while ($argv[$i])
    {
      if ($argv[$i] == "-n" && isset($argv[$i + 1]) == TRUE)
	if (($team = get_team_name($argv[$i + 1])) == -1)
	  return (FALSE);
      if ($argv[$i] == "-p" && isset($argv[$i + 1]) == TRUE)
	if (($port = get_port($argv[$i + 1])) == -1)
	  return (FALSE);
      if ($argv[$i] == "-h" && isset($argv[$i + 1]))
	if (($host = get_host($argv[$i + 1])) == -1)
	  return (FALSE);
      $i++;
    }
  return (TRUE);
}

function	get_entry($argc, $argv, $p)
{
  if (($argc < 4) || ($argc > 7))
    return (FALSE);
  if (get_args($argv, &$port, &$team, &$host) == FAlSE)
    return (FALSE);
  if ($host == NULL && $argc != 5)
    return (FALSE);
  if ((isset($port) == TRUE) && (isset($team) == TRUE))
    {
      if (isset($host) == FALSE)
	{
	  if ($p->init(1, $team, $port) == FALSE)
	    return (FALSE);
	}
      else
	if ($p->init(1, $team, $port, $host) == FALSE)
	  return (FALSE);
    }
  else
    return (FALSE);
  return (TRUE);
}

?>