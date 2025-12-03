#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int status;

    // fork로 자식 프로세스 생성
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // [Child Process]
        // 조건 1: 본인의 PID와 PPID 출력 [cite: 8]
        printf("Child process PID: %d\n", getpid());
        printf("Child process PPID: %d\n", getppid());
        
        // 조건 2: 종료 시 status code 7 반환 [cite: 9]
        exit(7);
    } else {
        // [Parent Process]
        // 조건 1: 본인의 PID와 PPID 출력 [cite: 8]
        printf("Parent process PID: %d\n", getpid());
        printf("Parent process PPID: %d\n", getppid());

        // 조건 3: 자식 프로세스가 끝나기를 기다림 (waitpid) [cite: 10]
        pid_t child_pid = waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            // 조건 3: 자식이 반환한 status code 출력 (WEXITSTATUS 매크로 사용) [cite: 10, 11]
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}