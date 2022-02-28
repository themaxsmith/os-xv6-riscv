    // 1B by Maxwell Smith
    // test nice function to see if it sets it correctly 

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char* argv[])
{
 
 // convert strimg to int
    int value = atoi(argv[1]);

    // call system call of nice
    int result = nice(value);

if (result == 0){
    // gets args 
    char **arr = (char **)&argv[2];
  
    //run the program
    exec(arr[0], arr);
    printf("failed %s",*arr[0]);

  exit(0);

}else{
    printf("error in running nice");
}
  exit(0);
}
