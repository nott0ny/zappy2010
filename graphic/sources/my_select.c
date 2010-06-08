
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "client.h"

void my_select(t_client *cl)
{
  int n;

  if ((n = select(cl->sock + 1, &cl->rdfs, &cl->wrfs, 0, 0)) == -1)
    error("my_select()");
  return ;
}
