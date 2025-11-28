#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 128 

int main() {
    char buf[BUF_SIZE];
    int n;
    while (1) {
        n = read(0, buf, BUF_SIZE);
        if (n == 0) {
            printf("Detected EOF (Ctrl + D)\nTerminating read loop...\n");
            break;
        }
        if (n < 0) {
            perror("Read Error");
            exit(1);
        }
        write(1, buf, n);
    }
    return 0;
}