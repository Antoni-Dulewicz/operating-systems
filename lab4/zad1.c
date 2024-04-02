#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    
    if(argc < 2){
        return 1;
    }

    int procNumber = atoi(argv[1]);

    

    for(int i = 0; i < procNumber; i++){
        pid_t pid;
        pid = fork();
        if(pid == 0){
            printf("This proces pid is: (%d) and parent pid is (%d)\n",getpid(),getppid());
            exit(0);
        }
    }

    for(int i = 0; i < procNumber; i++){
        wait(NULL);
    }

    printf("%s\n",argv[1]);
    return 0;
}