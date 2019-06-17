#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){

    pid_t pid;
    pid = fork();

    if (pid<0){
    printf("*** ERROR\n");
    return 1;
    }

   else if (pid==0){

    printf("pid: %d\n", getpid());
    printf("ppid: %d\n", getppid());
    exit(0);
    //sleep(10); //child process sleep for a while
    //printf("ppid: %d\n", getppid());
    }

    else {
    sleep(30);
    //sleep(6); // parent process also sleep
    //raise(SIGKILL);
   // exit(0); // then parent process exited, do not doing wait() system call, then child process become orphan process
    }

return 0;
}
