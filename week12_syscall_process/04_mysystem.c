#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

// mysystem 함수 구현
int mysystem(const char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        return -1; 
    }

    if (pid == 0) {
       
        execl("/bin/sh", "sh", "-c", command, (char *)0);
        
        // execl 실패 시
        exit(127);
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}

int main(void) {
    
    system("ls -l | wc -l");
    system("find . -name '*.c'");

    // mysystem("ls -l | wc -l");
    // mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}