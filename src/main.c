#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("请输入一个目录\n");
    return -1;
  }
  const char * dirPath = argv[1];
  printf("%s\n", dirPath);
  DIR *dir = NULL;
  dir = opendir(dirPath);
  if (dir == NULL) {
    printf("无法打开文件夹\n");
    return -1;
  }
  struct dirent *dirp = NULL;
  while (1) {
    dirp = readdir(dir);
    if (dirp != NULL) {
      printf("%s\n", dirp->d_name);
    } else {
      break;
    }
  }
  closedir(dir);
  return 0;
}
