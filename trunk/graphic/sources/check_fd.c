#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "client.h"

#define WELCOME "BIENVENUE\n"

void check_fd(t_client *cl)
{
  int check;

  if (FD_ISSET(cl->sock, &cl->rdfs))
    {
      receive_command(cl);
      while ((check = rb_has_cmd(cl->read_buff)) > 0)
	{
	  memset(cl->cmd, 0, MAXCMD_LEN);
	  rb_read(cl->read_buff, (unsigned char*)cl->cmd, check);
	  check_command(cl);
	}
    }
  if (FD_ISSET(cl->sock, &cl->wrfs) && cl->f_send == 1)
    {
      printf("Client send to server: %s", cl->send_buff);
      write(cl->sock, cl->send_buff, strlen(cl->send_buff));
      cl->f_send = 0; 
    }
}
 
