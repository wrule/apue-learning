#include <stdio.h>
#include <unistd.h>

int main() {
  printf("你好，我的进程PID是: %ld\n", (long int)getpid());
  return 0;
}
