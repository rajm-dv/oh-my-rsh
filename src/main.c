#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *BUILTINS[] = {"exit", "echo", "type", "cd", "pwd"};
const int BUILTINS_LEN = sizeof(BUILTINS) / sizeof(BUILTINS[0]);

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  while (1) {
    printf("$ ");

    char command[1024];
    if (fgets(command, sizeof(command), stdin) == NULL) {
    }

    *strchr(command, '\n') = '\0';
    int found = 0, pos = -1;
    for (int i = 0; i < BUILTINS_LEN; i++) {
      if (strncmp(command, BUILTINS[i], strlen(BUILTINS[i])) == 0) {
        found = 1;
        pos = i;
        break;
      }
    }

    if (!found) {
      printf("%s: command not found\n", command);
    }

    switch (pos) {
      case 0:
        exit(0);
        break;
      case 1:
        printf("%s\n", command+5);
        break;
      case 2:
        // execute type command
        break;
      case 3:
        // execute cd command
        break;
      case 4:
        // execute pwd command
        break;
      default:
        continue;
    }
  }

  return 0;
}
