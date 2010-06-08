
#include <stdlib.h>
#include <unistd.h>

#include "client.h"

void  init_cl(t_client *cl)
{
  cl = xmalloc(sizeof(t_client)));
  /rb_init(&cl->read_buff, MAXCMD_LEN);*/
  cl->port = 0;
  cl->sock = 0;
  cl->addrlen = 0;
  cl->f_send = 0;
  cl->fx = xmalloc(sizeof(t_graph*));
  cl->proto = NULL;
  cl->host = NULL;
}
