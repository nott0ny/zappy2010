<?php
// class_player.php for class_player in /u/all/veau-g_a/cu/rendu/c/zappy2010/ia
// 
// Made by adrien veau-greiner
// Login   <veau-g_a@epitech.net>
// 
// Started on  Tue May  4 21:58:25 2010 adrien veau-greiner
// Last update Thu May 13 18:29:13 2010 thomas luquet
//

class			Player extends Communication
{
  public		$team_name;
  protected		$num_client;

  protected		$id;
  private		$nb_player;
  private		$level;
  private		$health;
  private		$inventory;//array
  private		$vision;// array


  public function	__construct()
  {
    $port = 0;
    $host = NULL;
    $id = 0;
    $nb_player = 0;
    $team_name = NULL;
    $level = 0;
    $health = 1260;
    $inventory = array();
    $vision = array();
  }

  public function	init($i, $t, $p, $h = "localhost")
  {
    /*
     A Mettre dans le construct.
    */
    $this->id = $i;
    $this->team_name = $t;

    $this->set_port($p);
    $this->set_host($h);

    /* est ce au bon endroit ?*/
    aff_ok("Initializing Zappy Client ".$this->id);
    /*
    aff_ok("Configuration : team name: ".$this->team_name."\n\t\tport: "
	   .$this->port."\n\t\thost: ".$this->host);
    */
    return (TRUE);

    /* useless... car dans la class comm
     if (init_comm_server($this->sock) == FALSE)
    return (FALSE);
    */
  }


  public function	see()
  {
    echo "en cours...\n";
  }

  public function	checkInventory()
  {
    echo "en cours...\n";
  }

  public function	forwad()
  {
    echo "en cours...\n";
  }
  public function	turn($direction) // (left | right)
  {
    echo "en cours...\n";
  }

  public function	pickup($what) // (bouff | pierre)
  {
    echo "en cours...\n";
  }

  public function	broadcastMsg($message)
  {
    echo "en cours...\n";
  }

  public function	spellCasting()
  {
    echo "en cours...\n";
  }

  public function	repulse()
  {
    echo "en cours...\n";
  }

  public function	replicate()
  {
    echo "en cours...\n";
  }

  public function	checkNbPlayer()
  {
    echo "en cours...\n";
  }

  public function	teamName()
  {
    echo "en cours...\n";
  }

  public function	deathPlayer()
  {
    echo "en cours...\n";
  }

  public function	__destruct()
  {
    echo rouge("QUIT Player\n");
  }
}

?>