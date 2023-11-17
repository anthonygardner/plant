#include <stdio.h>
#include <sys/file.h>

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; ++i) {
    printf("%s%s", argv[i], (i < argc-1) ? " " : "");
  }

  // if the user provides a -p -> assume this is a port they are trying to communicate with and check if it is open

  return 0;
}
