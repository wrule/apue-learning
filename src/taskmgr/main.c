#include <stdio.h>

#define MAX_LINE_NUM 4096

int main() {
  char buffer[MAX_LINE_NUM];
  while (fgets(buffer, MAX_LINE_NUM, stdin) != NULL) {
    fputs(buffer, stdout);
  }
  return 0;
}
