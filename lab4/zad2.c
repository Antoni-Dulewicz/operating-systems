#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <wait.h>

int global = 0;

int main(int argc, const char *argv[]){
    printf("Program z zad2\n");

    int local = 0;

    pid_t pid = fork();

    if(pid < 0){
        perror("Fork error\n");
        return 1;
    }

    if(pid == 0){
        printf("child process:\n");
        global++;
        local++;
        printf("child pid = %d, parent pid = %d\n",getpid(),getppid());
        printf("child's local = %d, child's global = %d\n",local,global);
        
        execl("/bin/ls","ls",argv[1],NULL);

        perror("Exec error\n");
        exit(errno);

    }else{

        int childStatus;
        wait(&childStatus);
        printf("---------------------\n");
        printf("parent process\n");
        printf("parent pid = %d, child pid = %d\n",getpid(),pid);

        printf("Child exit code: %d\n", WEXITSTATUS(childStatus));
        printf("Parent's local = %d, parent's global = %d\n",local,global);

        return WEXITSTATUS(childStatus);
    }
    return 0;
}