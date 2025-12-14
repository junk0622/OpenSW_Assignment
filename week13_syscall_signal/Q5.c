#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct two_double {
    double a;
    double b;
};

struct two_double data;

void sigint_handler(int _signo) {
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void) {
    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    // 핸들러 설정 (문제의 코드와 동일)
    sa_sigalrm.sa_handler = sigint_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;
    if(sigaction(SIGALRM, &sa_sigalrm, NULL) == -1){
        perror("sigaction error: ");
        exit(0);
    }

    data = zeros;
    alarm(1);

    // 블로킹을 위한 시그널 집합 생성
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGALRM); // SIGALRM을 집합에 추가

    while(1) {
        // [BLOCK SIGALRM] 데이터 쓰기 전 차단
        sigprocmask(SIG_BLOCK, &set, NULL); 
        data = zeros;
        // [UNBLOCK SIGALRM] 데이터 쓴 후 해제
        sigprocmask(SIG_UNBLOCK, &set, NULL);

        // [BLOCK SIGALRM]
        sigprocmask(SIG_BLOCK, &set, NULL);
        data = ones;
        // [UNBLOCK SIGALRM]
        sigprocmask(SIG_UNBLOCK, &set, NULL);
    }
    return 0;
}