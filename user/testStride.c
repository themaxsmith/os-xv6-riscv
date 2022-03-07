    // 1C by Maxwell Smith
    // test stride by sleeping by 2 seconds and getting pstats every 2 seconds

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
        printf("ID: %d pid: %d  inuse: %d nice: %d runtime: %d stride: %d pass: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i], stats.runtime[i], stats.stride[i], stats.pass[i]);
    }

    if(fork() == 0){
         nice(14);
         while(1){}
    }

    if(fork() == 0){
         nice(19);
         while(1){}
    }

    
    getpstat(&stats); 

// loops stats and prints it out
      for(int i=0; i < sizeof(&stats.inuse); i++)
    {
        printf("ID: %d pid: %d  inuse: %d nice: %d runtime: %d stride: %d pass: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i], stats.runtime[i], stats.stride[i], stats.pass[i]);
    }

    sleep(2);

    getpstat(&stats); 

// loops stats and prints it out
      for(int i=0; i < sizeof(&stats.inuse); i++)
    {
        printf("ID: %d pid: %d  inuse: %d nice: %d runtime: %d stride: %d pass: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i], stats.runtime[i], stats.stride[i], stats.pass[i]);
    }
    sleep(2);
    getpstat(&stats); 

// loops stats and prints it out
      for(int i=0; i < sizeof(&stats.inuse); i++)
    {
        printf("ID: %d pid: %d  inuse: %d nice: %d runtime: %d stride: %d pass: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i], stats.runtime[i], stats.stride[i], stats.pass[i]);
    }

  exit(0);
}
