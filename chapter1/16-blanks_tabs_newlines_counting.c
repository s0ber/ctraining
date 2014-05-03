#include <stdio.h>

int main(int argc, char const *argv[])
{
  int c;
  int nb, nt, nl;

  nb = 0;
  nt = 0;
  nl = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
      ++nb;

    if (c == '\t')
      ++nt;

    if (c == '\n')
      ++nl;
  }

  printf("Blanks: %d, tabs: %d, lines: %d \n", nb, nt, nl);
  return 0;
}
