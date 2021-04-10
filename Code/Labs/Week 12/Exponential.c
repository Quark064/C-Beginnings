/* William Anderson - 4/9/2021 - C Lab */
#include <stdio.h>

double exponential(double x) {
  double t;

  if (-1e-9 <= x && x <= 1e-9) {
    return 1.0 + x;
  }

  t = exponential(x / 2.0);
  return t * t;
}


int main(int argc, char **argv) {
  double x, y;

  printf("Please enter a real number:\n");
  scanf("%lf", &x);

  y = exponential(x);

  printf("exp(%lf) = %le\n", x, y);

  return 0;
}
