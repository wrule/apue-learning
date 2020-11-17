#include <stdio.h>

int main() {
  int c = 0;
  while ((c = fgetc(stdin)) != EOF) {
    if (fputc(c, stdout) == EOF) {
      return -1;
    }
  }
  if (ferror(stdin)) {
    return -1;
  }
  return 0;
}
