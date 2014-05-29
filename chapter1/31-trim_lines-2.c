#include <stdio.h>
#include <string.h>
#include "textline.h"

void trim(char line[]);

int main(int argc, char const *argv[])
{
  char line[MAXLINE];

  while (gettextline(line) > 0) {
    trim(line);
    // do nothing if is empty line
    if (line[1] == '\0')
      continue;
    printf("%s", line);
  }

  return 0;
}

void trim(char s[])
{
  int i;
  int startpos = -1, endpos = -1;

  for (i = 0; i < strlen(s); ++i) {
    if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
      if (startpos == -1) {
        startpos = i;
      }
      endpos = i;
    }
  }

  int trimmedlen = endpos - startpos;

  i = 0;
  while (i <= trimmedlen) {
    s[i] = s[i + startpos];
    i++;
  }
  s[i] = '\n';
  s[i + 1] = '\0';
}
