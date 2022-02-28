    // 1B by Maxwell Smith
    // Prints the table of process stats 

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"
int
main(void)
{
    // get current process stats
    struct pstat stats; 
    getpstat(&stats); 

// loops stats and prints it out
      for(int i=0; i < sizeof(&stats.inuse); i++)
    {
        printf("ID: %d pid: %d  inuse: %d nice: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i]);
    }

  exit(0);
}
