/* William Anderson - 2/19/2021 - C Lab */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    short invalid = 1;
    int userIn, i;
    double ratio;
    long long fibI, fibIM1 = 1.0, fibIM2 = 0.0;

    while (invalid) {
      printf("Please enter an integer that is at least 2: ");
      scanf("%d", &userIn);

      if (userIn >= 2) {
        invalid = 0;
      }
      else {
        printf("Sorry. Your input is incorrect. Please try again.\n\n");
      }
    }

    for (i = 2; i <= (userIn + 1); i++) {
      fibI = fibIM1 + fibIM2;
      fibIM1 = fibIM2;
      fibIM2 = fibI;
    }

    ratio = ((double)fibI / fibIM1);
    printf("fib(%d) = %lld, fib(%d) / fib(%d) = %f\n", userIn, fibI, userIn, (userIn - 1), ratio);

  return 0;
}
