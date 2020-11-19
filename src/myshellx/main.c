#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 4096

/**
 * errRet 打印错误信息并且退出程序
 **/
void errRet(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(-1);
}

/**
 * waitTask 等待进程退出
 **/
void waitTask(pid_t pid) {
  int status = 0;
  if ((pid = waitpid(pid, &status, 0)) < 0) {
    errRet("等待进程错误");
  }
}

/**
 * runCmd 运行命令
 **/
void runCmd(char * cmd) {
  pid_t pid = fork();
  if (pid > 0) {
    waitTask(pid);
  } else if (pid < 0) {
    errRet("fork进程出错");
  } else {
    execlp(cmd, cmd, (char *)0);
    fprintf(stderr, "不能执行: %s\n", cmd);
    exit(127);
  }
}

/**
 * inputLoop 输入命令循环
 **/
void inputLoop() {
  char buffer[BUFFER_SIZE];
  while (1) {
    printf(">> ");
    char *res = fgets(buffer, BUFFER_SIZE, stdin);
    if (res != NULL) {
      size_t strLen = strlen(buffer);
      if (buffer[strLen - 1] == '\n') {
        buffer[strLen - 1] = '\0';
      }
      runCmd(buffer);
    } else {
      break;
    }
  }
}

/**
 * 主函数
 **/
int main() {
  printf("鸡毛Shell\n");
  inputLoop();
  return 0;
}
