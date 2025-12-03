#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // 조건 2: 인자가 부족할 경우 에러 처리 [cite: 21, 22]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <program path> [OPTION] ...\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // [Child Process]
        // 조건 3: execve를 사용하여 전달받은 프로그램 실행 [cite: 23]
        // argv[1]은 실행할 프로그램 경로, &argv[1]은 {경로, 옵션1, 옵션2, ..., NULL} 형태가 됨
        if (execve(argv[1], &argv[1], NULL) == -1) {
            // 조건 4: execve 실패 시, child는 exit code 1로 종료 [cite: 24]
            perror("execve failed"); // 예시 화면처럼 에러 메시지 출력 필요 시 사용
            exit(1);
        }
    } else {
        // [Parent Process]
        int status;
        // 조건 5: waitpid를 사용하여 기다리고, exit code 출력 [cite: 25]
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}