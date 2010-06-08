#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "client.h"

#define WELCOME "BIENVENUE"

void check_fd(t_client *cl)
{
  int check;

  if (FD_ISSET(cl->sock, &cl->rdfs))
    {
      cl->cmd = xmalloc(sizeof(char*) * MAXCMD_LEN);
      cl->cmd = receive_command(cl);
      /*if ((check = rb_has_cmd(cl->read_buff)) > 0)
	{
	  rb_read(cl->read_buff, (unsigned char*)cl->cmd, check);
	  if (strcmp(cl->cmd, WELCOME) == 0)
	    write(cl->sock, "GRAPHIC\n", 8);
	  printf("-%s-\n", cl->cmd);
	  }*/
      /*check_command(cl);*/
      free(cl->cmd);
    }
  if (FD_ISSET(cl->sock, &cl->wrfs) && cl->f_send == 1)
    {
      printf("Client send to server: %s", cl->send_buff);
      write(cl->sock, cl->send_buff, strlen(cl->send_buff));
      cl->f_send = 0; 
    }
}
 
