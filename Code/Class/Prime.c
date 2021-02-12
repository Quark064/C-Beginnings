#include <stdio.h>

int main(int argc, char **argv) {
  int i, n, isprime = 1;

  /* Have the user enter an integer >= 2 */
  printf("Please enter an integer greater than or equal to 2: ");
  scanf("%d", &n);

  /* Check if the user entered an integer >= 2 */
  if (n >= 2) {
    for (i = 2; i < n; i++) {
      if (n % i == 0) {
        isprime = 0;
        break;
      }
    }

    if (isprime) {
      printf("%d is prime.\n", n);
    } else {
      printf("%d is not prime.\n", n);
    }

  } else {
    /* Print an error message */
    printf("The integer you entered, %d, is not greater than or equal to 2.\n", n);
  }

  return 0;
}
