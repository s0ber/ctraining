#include <stdio.h>

int main(int argc, char const *argv[])
{
  float cels, fahr;
  int lower, upper, step;

  lower = -20;
  upper = 150;
  step = 10;

  cels = lower;

  while (cels <= upper) {
    fahr = (9.0 / 5.0) * cels + 32.0;
    printf("%3.0f\t%3.3f\n", cels, fahr);
    cels = cels + step;
  }
  return 0;
}
