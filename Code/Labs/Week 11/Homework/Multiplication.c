/* William Anderson - 4/2/2021 - C Homework */
#include <stdio.h>

int getUserNum(int number) {
  int userIn;

  while (1) {
    printf("Please enter positive int #%d: ", number);
    scanf("%d", &userIn);

    if (userIn >= 0) return userIn;

    printf("Sorry, thats not a valid number, please try again..\n\n");
  }
}

int multiplication(int a, int b) {
  int localTotal = 0;

  int localA = a * 2;
  int localB = b / 2;

  if (b % 2 != 0) {
    localTotal += a;
  }
  if (b != 0) {
    return localTotal + multiplication(localA, localB);
  }
  return localTotal;
}


int main(int argc, char const *argv[]) {
  int numberA = getUserNum(1);
  int numberB = getUserNum(2);

  printf("\n");
  printf("Answer via R.P.M: %d * %d = %d\n", numberA, numberB, multiplication(numberA, numberB));
  printf("Answer via '*':   %d * %d = %d\n", numberA, numberB, numberA * numberB);
  return 0;
}
