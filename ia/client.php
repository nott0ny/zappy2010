#!/usr/local/bin/php -c /afs/epitech.net/users/epitech_2012/luquet_t/cu/php.ini
<?php
//#!/usr/local/bin/php -c /afs/epitech.net/users/epitech_2013/veau-g_a/cu/php.ini
//
// main.php for main in /u/all/veau-g_a/cu/rendu/c/zappy2010/ia
// 
// Made by adrien veau-greiner
// Login   <veau-g_a@epitech.net>
// 
// Started on  Tue May  4 23:39:16 2010 adrien veau-greiner
// Last update Thu May 13 16:40:38 2010 thomas luquet
//

  /*Client numero 1

/usr/local/lib/php/

   -> ecouter serveur
   -> verifier stack de reponse
   -> mettre a jour l'etat du trantorien
   -> definir les stacks de commande
   -> executer stack de commande
  */

require("include.php");

function main($argc, $argv)
{
  $p = new Player();

  if (get_entry($argc, $argv, $p) == FALSE)
    {
      aff_help();
      return ;
    }
  enter_the_game($p);
}

main($argc, $argv)

?>