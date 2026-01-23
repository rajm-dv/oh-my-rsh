#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  printf("$ ");

  char command[256];
  if (fgets(command, sizeof(command), stdin) != NULL) {
    command[strcspn(command, "\n")] = 0;
    printf("%s: command not found\n", command);
  }

  return 0;
}
