#include <sys/types.h>
#include <unistd.h>

#include "client.h"

void init_fd(t_client *cl)
{
  FD_ZERO(&(cl->rdfs));
  FD_ZERO(&(cl->wrfs));
  FD_SET(cl->sock, &(cl->rdfs));
  FD_SET(cl->sock, &(cl->wrfs));
}

