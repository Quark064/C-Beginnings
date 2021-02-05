/* William Anderson - 2/5/2021 - C Lab */
#include <stdio.h>

int main(int argc, char **argv) {
  long long upc, upcCopy;
  int tick = 1, evenSum = 0, oddSum = 0, modStorage, checkSum;

  printf("Please enter a UPC code with up to 12 digits: ");
  scanf("%lld", &upc);

  /* Check if the user entered a positive number with up to 12 digits */
  if ((((long long)0ll) <= upc) && (upc <= ((long long)999999999999ll))) {

    upcCopy = upc;

    while (upcCopy > 0) {
      modStorage = (upcCopy % 10);
      upcCopy = upcCopy / 10;

      if (tick % 2 == 0) {
        evenSum += modStorage;
      } else {
        oddSum += modStorage;
      }

      tick += 1;
    }

    checkSum = (evenSum * 3) + oddSum;

    if (checkSum % 10 == 0) {
      printf("The code you entered, %lld, is a valid UPC code.\n", upc);
    } else {
      printf("The code you entered, %lld, does not correspond to a valid UPC "
             "product code.\n",
             upc);
    }

  } else {
    printf("The code you entered, %lld, is incorrect as it is negative or has "
           "too many digits.\n",
           upc);
  }

  return 0;
}
