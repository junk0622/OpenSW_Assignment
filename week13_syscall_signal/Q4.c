#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

// SIGINT 핸들러: ls 실행 [cite: 15]
void sigint_handler(int signum) {
    printf("[SIGINT handler] ------------\n");
    pid_t pid = fork();
    if (pid == 0) { // Child
        char *argv[] = {"/usr/bin/ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
        exit(1); // exec 실패 시 종료
    } else { // Parent
        wait(NULL); // [cite: 16]
    }
}

// SIGQUIT 핸들러: date 실행 [cite: 17]
void sigquit_handler(int signum) {
    printf("[SIGQUIT handler] ------------\n");
    pid_t pid = fork();
    if (pid == 0) { // Child
        char *argv[] = {"/usr/bin/date", NULL};
        execve("/usr/bin/date", argv, NULL);
        exit(1);
    } else { // Parent
        wait(NULL); // [cite: 18]
    }
}

// SIGALRM 핸들러: whoami 실행 후 알람 재설정 [cite: 19]
void sigalrm_handler(int signum) {
    printf("[SIGALRM handler] ------------\n");
    pid_t pid = fork();
    if (pid == 0) { // Child
        char *argv[] = {"/usr/bin/whoami", NULL};
        execve("/usr/bin/whoami", argv, NULL);
        exit(1);
    } else { // Parent
        wait(NULL); // [cite: 20]
        alarm(3);   // 알람 재설정 [cite: 20]
    }
}

int main(void) {
    // 핸들러 등록
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalrm_handler);

    alarm(3); // 최초 알람 설정 [cite: 14]

    while(1) {
        sleep(1);
    }
    return 0;
}