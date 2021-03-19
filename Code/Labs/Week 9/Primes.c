/* William Anderson - 3/19/2021 - C Lab */
#include <stdio.h>


int get_pos_int() {
  int valid = 0;
  int userIn;

  while (!valid) {
    printf("Please enter a positive (non-zero) integer: ");
    scanf("%d", &userIn);

    if (userIn > 0) {
      valid = 1;
    }
    else {
      printf("Sorry, that was not a valid input. Please try again...\n\n");
    }
  }

  return userIn;
}


int is_prime(int n) {
  int isPrime = 0;
  int i;

  if (n <= 0) {
    return isPrime;
  }

  if (n == 1 || n == 2) {
    isPrime = 1;
    return isPrime;
  }

  for (i = 2; i < n; i++) {
    if (n % i == 0) {
      return isPrime;
    }
  }

  isPrime = 1;
  return isPrime;
}


int number_of_primes(int n) {
  int count = 0;
  int i;

  for (i = 0; i < n; i++) {
    if (is_prime(i)) {
      count += 1;
    }
  }
  return count;
}


double ratio_primes(int n) {

  if (n <= 0) {
    return 0.0;
  }

  return ((double) number_of_primes(n)) / (((double) n));
}

int main(int argc, char **argv) {
  int n;

  n = get_pos_int();

  if (is_prime(n)) {
    printf("\n");
    printf("%d is prime.\n", n);
  } else {
    printf("\n");
    printf("%d is not prime.\n", n);
  }

  printf("\n");
  printf("There are %d prime numbers between 1 and %d.\n", number_of_primes(n), n-1);
  printf("%3.3lf%% of the numbers between 1 and %d are prime.\n", ratio_primes(n) * 100.0, n-1);

  return 0;
}
