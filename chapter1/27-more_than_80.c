#include <stdio.h>
#define MINLINE 80
#define MAXLINE 100 /* maximum input line size */

int gettextline(char line[], int maxline);

int main(int argc, char const *argv[])
{
  int len;
  char line[MAXLINE];

  while ((len = gettextline(line, MAXLINE)) > 0) {
    --len;
    if (len >= MINLINE)
      printf("Perfect, more than 80 chars (%d)! Here\'s your string:\n%s\n", len, line);
    else
      printf("This line contains %d chars, that's not enough.\n", len);
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
