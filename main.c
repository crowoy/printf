#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>

void printf_normal (const char * str) {
    printf(str);
}

void printf_syscall (const char * str) {
    syscall(__NR_write, 1, str, strlen(str));
}

void printf_write (const char * str) {
    write(1, str, strlen(str));
}

int main (int argc, char* argv[]) {
    const char n[] = "Hello World!\n";
    printf_normal(n);
    printf_syscall(n);
    printf_write(n);
}
