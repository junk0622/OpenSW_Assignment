#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
pid_t pid = getpid();
printf("pid: %d\n", pid);
return 0;
}

