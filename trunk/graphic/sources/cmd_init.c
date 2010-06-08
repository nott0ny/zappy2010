
#include <stdio.h>

#include "client.h"

int cmd_init(__attribute__((unused))char **params,
	     __attribute__((unused))t_client *cl)
{
  printf("cmd_init()\n");
  cl->f_send = 1;
  cl->send_buff = NAME;
  return (0);
}
