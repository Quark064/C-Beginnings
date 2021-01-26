#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a;
  int b;
  int sum;
  int diff;
  int prod;
  int quot;
  int remainder;

  /* Get Int Numbers */
  printf("Please enter a number (int): ");
  scanf("%d", &a);

  printf("Please enter another number (int): ");
  scanf("%d", &b);

  /* Do Operations On Variables */
  sum = a + b;
  diff = a - b;
  prod = a * b;
  quot = a / b;
  remainder = a % b;

  /* Return Values To User Via Print Statements */
  printf("%d + %d = %d\n", a, b, sum);
  printf("%d - %d = %d\n", a, b, diff);
  printf("%d * %d = %d\n", a, b, prod);
  printf("%d / %d = %d\n", a, b, quot);
  printf("%d mod %d = %d\n", a, b, remainder);

  return 0;
}
