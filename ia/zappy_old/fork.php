<?php
// fork.php for fork in /u/all/luquet_t/cu/Desktop/zappy
// 
// Made by thomas luquet
// Login   <luquet_t@epitech.net>
// 
// Started on  Mon Jun 22 14:08:10 2009 thomas luquet
// Last update Mon Jun 22 15:09:13 2009 thomas luquet
//



function	call_my_egg($glob, $i)
{

  aff_client("Fork resussit !");
  $glob['time_to_fork'][$i]['done'] = 1;

  $to_send = "./client.php -n ".$glob['equipe']." -p ".
    $glob['port']." -h ".$glob['host'];

  exec($to_send." > /dev/null &");

  echo yellow('
           :::::::::: ::::::::  :::::::::  :::    ::: :::::::::: :::::::::
          :+:       :+:    :+: :+:    :+: :+:   :+:  :+:        :+:    :+:
         +:+       +:+    +:+ +:+    +:+ +:+  +:+   +:+        +:+    +:+
        :#::+::#  +#+    +:+ +#++:++#:  +#++:++    +#++:++#   +#+    +:+
       +#+       +#+    +#+ +#+    +#+ +#+  +#+   +#+        +#+    +#+
      #+#       #+#    #+# #+#    #+# #+#   #+#  #+#        #+#    #+#
     ###        ########  ###    ### ###    ### ########## #########
');

  return($glob);
}

?>