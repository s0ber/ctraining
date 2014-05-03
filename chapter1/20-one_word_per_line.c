#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{
  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      putchar('\n');
      continue;
    } else if (state == OUT) {
      state = IN;
    }
    putchar(c);
  }
  return 0;
}
