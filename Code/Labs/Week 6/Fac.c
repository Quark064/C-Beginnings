/* William Anderson - 2/19/2021 - C Lab */
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    short invalid = 1;
    double x, mathLibCalc, ci = 1.0, pi = 1.0, runningTotal = 0.0;
    int y, i;

    while (invalid) {
      printf("Please enter a real number between -1.0 and 1.0: ");
      scanf("%lf", &x);

      if ((x >= -1) && (x <= 1)) {
        invalid = 0;
      }
      else {
        printf("Sorry. Your input, %f, is out of bounds. Try again.\n", x);
      }
    }

    invalid = 1;
    while (invalid) {
      printf("Please enter a non-negative integer number: ");
      scanf("%d", &y);

      if (y >= 0) {
        invalid = 0;
      }
      else {
        printf("Sorry. Your input, %d, is out of bounds. Try again.\n", y);
      }
    }

    for (i = 0; i <= y; i++) {
      if (i == 0) {
        runningTotal += 1;
      }
      else {
        ci /= i;
        pi *= x;
        runningTotal += ci * pi;
      }
    }

    mathLibCalc = exp(x);
    printf("Our approximation of exp(%f) = %f.\n", x, runningTotal);
    printf("The math library says: exp(%f) = %f.\n", x, mathLibCalc);

  return 0;
}
