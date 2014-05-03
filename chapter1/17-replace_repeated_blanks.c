#include <stdio.h>

int main(int argc, char const *argv[])
{
  int c;
  int prev_was_blank;

  prev_was_blank = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
    {
      if (prev_was_blank == 1)
        continue;
      prev_was_blank = 1;
    } else {
      prev_was_blank = 0;
    }

    putchar(c);
  }

  return 0;
}
