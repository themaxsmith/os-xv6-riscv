    // HW1 by Maxwell Smith
    // the expected result if we call it AFTER the sleep is that process count will be the n + 1
    // this is due to the child proccess being forked and exiting, it will now be a zombie process
    // this allows the parent process to get the exit value if it is needed

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
    // get current process count
    int count = pcount();
    printf("process count: %d\n", count);


    printf("creating new process\n");
  if(fork() > 0){
    sleep(5);  // Let child exit before parent.

   int countNEW = pcount(); // Get the new process count and write
    printf("[NEW] process count: %d\n", countNEW);  

  }else{
   printf("exiting child process\n");
  }
  exit(0);
}
