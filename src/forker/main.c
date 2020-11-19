#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  printf("主进程: 你好世界\n");
  pid_t pid = fork();
  if (pid < 0) {
    printf("主进程: fork失败\n");
  } else if (pid > 0) {
    printf("主进程: Pid: %d\n", pid);
    int status = 0;
    if ((pid = waitpid(pid, &status, 0)) < 0) {
      printf("主进程: 等待进程错误\n");
    }
  } else {
    printf("子进程: 你好中国\n");
  }
  return 0;
}
