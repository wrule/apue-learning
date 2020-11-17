#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
  uint8_t buffer[BUFFER_SIZE];
  ssize_t readNum = 0;
  while((readNum = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
    ssize_t writeNum = write(STDOUT_FILENO, buffer, readNum);
    if (writeNum != readNum) {
      return -1;
    }
  }
  if (readNum < 0) {
    return -1;
  }
  return 0;
}
