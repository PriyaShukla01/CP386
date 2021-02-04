#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 == 0){ //executed the first child process
        
        printf("First child is executed. PID = %d.\n", getpid());  
    } else {
        pid2 = fork();
        if (pid2 == 0){ //executed the second child process
           
            printf("Second child is executed. PID = %d\n", getpid());
        } else {
            pid3 = fork();
            if (pid3 == 0){ //executed the third child process
                
                printf("third child is executed. PID = %d\n", getpid());
            }
            else { //executed the parent process
                
                printf("Parent process is executed. PID = %d\n", getpid());
            }
        }
    }
    return 0;
}