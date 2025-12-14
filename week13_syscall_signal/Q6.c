#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    sigset_t newset, pendingset;

    // 1. SIGINT 블로킹 설정 [cite: 27]
    sigemptyset(&newset);
    sigaddset(&newset, SIGINT);
    
    // 현재 블록 마스크에 SIGINT 추가
    if (sigprocmask(SIG_BLOCK, &newset, NULL) < 0) {
        perror("sigprocmask error");
    }

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");

    // 2. 5초간 대기 [cite: 28]
    sleep(5);

    // 3. Pending된 시그널 확인 [cite: 29]
    if (sigpending(&pendingset) < 0) {
        perror("sigpending error");
    }

    // SIGINT가 대기 중인지 확인 [cite: 30]
    if (sigismember(&pendingset, SIGINT)) {
        printf("\nSIGINT is pending\n");
    } else {
        printf("\nSIGINT is not pending\n");
    }
    
    // (선택사항) 종료 전 블로킹 해제하여 밀린 시그널 처리
    sigprocmask(SIG_UNBLOCK, &newset, NULL);

    return 0;
}