#include <stdio.h>
#include <sys/file.h>

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; ++i) {
    printf("%s%s", argv[i], (i < argc-1) ? " " : "");
  }

  return 0;
}
