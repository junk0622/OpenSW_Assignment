#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUF_SIZE 32 

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s [source] [dest1] [dest2] ...\n", argv[0]);
        exit(0);
    }

    int src_fd = open(argv[1], O_RDONLY);
    
    if (src_fd == -1) {
        perror("Source file open error");
        exit(1);
    }

    int num_dest = argc - 2;
    int *dest_fds = (int *)malloc(sizeof(int) * num_dest);

    for (int i = 0; i < num_dest; i++) {
        dest_fds[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (dest_fds[i] == -1) {
            perror("Dest file open error");
        }
    }

    char buf[BUF_SIZE];
    int n;

    while ((n = read(src_fd, buf, BUF_SIZE)) > 0) {

        write(1, buf, n);
        
        for (int i = 0; i < num_dest; i++) {
            if (dest_fds[i] != -1) {
                write(dest_fds[i], buf, n);
            }
        }
    }

    close(src_fd);
    for (int i = 0; i < num_dest; i++) {
        if (dest_fds[i] != -1) close(dest_fds[i]);
    }
    free(dest_fds);

    return 0;
}