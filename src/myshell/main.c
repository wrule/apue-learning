#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_NUM 4096

// errRet 打印错误信息并且退出程序
void errRet(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(-1);
}

int main() {
  char buffer[MAX_LINE_NUM];
  char *p = NULL;

  while (1) {
    printf(">> ");
    p = fgets(buffer, MAX_LINE_NUM, stdin);
    if (p != NULL) {
      if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
      }

      pid_t pid = fork();
      if (pid < 0) {
        errRet("fork进程失败");
      } else if (pid == 0) {
        execlp(buffer, buffer, (char *)0);
        fprintf(stderr, "不能执行: %s\n", buffer);
        exit(127);
      }

      int status = 0;
      if ((pid = waitpid(pid, &status, 0)) < 0) {
        errRet("等待进程错误");
      }
    } else {
      break;
    }
  }
  return 0;
}
