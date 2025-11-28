#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file1 name] ...\n", argv[0]);
        exit(0);
    }

    int fd;
    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);

        if (fd == -1) {
            printf("%s: ", argv[i]); // 파일명 먼저 출력하고
            perror("Open Failed");   // 에러 메시지 출력
        } else {
            printf("Opened successfully: %s (fd = %d)\n", argv[i], fd);
            close(fd);
            printf("Closed successfully: %s\n", argv[i]);
        }
    }
    return 0;
}