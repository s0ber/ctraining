#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */
#define IN 1
#define OUT 0

int gettextline(char line[], int maxline);
void trim(char line[]);
void reverse(char line[]);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
  char line[MAXLINE];

  while (gettextline(line, MAXLINE) > 0) {
    trim(line);
    // do nothing if is empty line
    if (line[1] == '\0')
      continue;
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

int gettextline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
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

  for (i = startpos; i < endpos; ++i)
  {
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
  int i;
  int len;

  for (i = 0; s[i] != '\n'; ++i)
    ;

  len = i;

  int k;
  k = 0;
  for (int i = len - 1; i >= 0; --i) {
    newline[k] = s[i];
    ++k;
  }
  newline[k] = '\n';
  newline[k + 1] = '\0';

  copy(s, newline);
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
