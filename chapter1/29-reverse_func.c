#include <stdio.h>
#include <string.h>
#include "textline.h"

#define IN 1
#define OUT 0

void trim(char line[]);
void reverse(char line[]);

int main(int argc, char const *argv[])
{
  char line[MAXLINE];

  while (gettextline(line) > 0) {
    trim(line);
    // do nothing if is empty line
    if (line[1] == '\0')
      continue;
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

void trim(char s[])
{
  char newline[MAXLINE];
  int i;
  int state;
  int startpos, endpos;

  state = OUT;
  startpos = endpos = -1;

  // clearing trailing spaces and tabs
  i = 0;
  while (s[i] != '\n') {
    if (s[i] == ' ' || s[i] == '\t') {
      if (state == IN)
        endpos = i;
      state = OUT;
    } else {
      state = IN;
      if (startpos == -1)
        startpos = i;
    }
    ++i;
  }

  if (state == IN)
    endpos = i;

  int k;
  k = 0;

  for (i = startpos; i < endpos; ++i) {
    newline[k] = s[i];
    ++k;
  }
  newline[k] = '\n';
  newline[k + 1] = '\0';

  copy(s, newline);
}

void reverse(char s[])
{
  char newline[MAXLINE];
  int i, k;
  int len = strlen(s);

  k = 0;
  for (i = len - 2; i >= 0; --i) {
    newline[k] = s[i];
    ++k;
  }
  newline[k] = '\n';
  newline[k + 1] = '\0';

  copy(s, newline);
}
