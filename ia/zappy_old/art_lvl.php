<?php
// art_lvl.php for art lvl up in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Fri Jun 19 21:02:18 2009 thomas luquet
// Last update Fri Jun 19 21:19:51 2009 thomas luquet
//

function	art_lvl($lvl)
{
  $lvl_art =array (
		   array(0 => 0),
		   array(1 => 1),
		   array(2 => "
                       __                     __   ______
                      |  |.-----.--.--.-----.|  | |__    |
                      |  ||  -__|  |  |  -__||  | |    __|
                      |__||_____|\___/|_____||__| |______|"
			  ),
		    array(3 => "
                       __    ___  _  _  ___  __      ___
                      (  )  (  _)( )( )(  _)(  )    (__ )
                       )(__  ) _) \\//  ) _) )(__    (_ \
                      (____)(___) (__) (___)(____)  (___/"
			  )
		    );
 echo magenta($lvl_art[$lvl]);
}
?>