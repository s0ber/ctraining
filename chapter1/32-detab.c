#include <stdio.h>
#include <string.h>
#include "textline.h"

int main(int argc, char const *argv[])
{
  char line[MAXLINE];

  while (gettextline(line) > 0) {
    // do nothing if is empty line
    if (line[1] == '\0')
      continue;
    printf("%s", line);
  }

  return 0;
}
