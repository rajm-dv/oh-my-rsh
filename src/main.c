#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  while (1) {
    printf("$ ");

    char command[256];
    if (fgets(command, sizeof(command), stdin)) {
      command[strcspn(command, "\n")] = 0;
      printf("%s: command not found\n", command);
    }
  }

  return 0;
}
