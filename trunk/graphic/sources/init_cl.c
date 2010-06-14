
#include <stdlib.h>
#include <unistd.h>

#include "client.h"

void  init_cl(t_client **clg)
{
  t_client *cl;

  cl = xmalloc(sizeof(t_client));
  cl->port = 0;
  cl->sock = 0;
  cl->addrlen = 0;
  cl->f_send = 0;
  cl->ingame = 0;
  cl->status = CL_INIT;
  cl->plist = NULL;
  cl->fx = xmalloc(sizeof(t_graph));
  cl->fx->map = xmalloc(sizeof(t_case));
  cl->fx->gui = xmalloc(sizeof(t_ui));
  cl->proto = NULL;
  cl->host = NULL;
  rb_init(&cl->read_buff, MAXCMD_LEN);
  *clg = cl;
}
