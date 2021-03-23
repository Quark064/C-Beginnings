
/* Program for basic mathematics

   (C) 2021 University of Alaska Anchorage

   Written by  Chr. Lauter          and

              William Anderson

*/

#include <stdio.h>


int get_integer() {
  int userIn;

  printf("Please enter a real number: ");
  scanf("%d", &userIn);

  return userIn;
}


int add(int a, int b) {
  return (a + b);
}


int sub(int a, int b) {
  return (a - b);
}


int mul(int a, int b) {
  return (a * b);
}


int quot(int a, int b) {
  if (b == 0) {   /* Just to prevent crashing... */
    return 0;
  }

  return (a / b);
}


int rem(int a, int b) {
  if (b == 0) {   /* Just to prevent crashing... */
    return 0;
  }

  return (a % b);
}


int power(int a, int b) {
  int i;
  int result = 1;

  if (a == 1) {
    return 1;
  }

  if (b == 0) {
    return 0;
  }

  if ((b < 0) && (a != 1)) {
    return 0;
  }

  for (i = 0; i < b; i++) {
    result = result * a;
  }

  return result;
}


int operation(char c, int a, int b) {
  int result;

  switch(c) {
    case '+':
      result = add(a, b);
      break;

    case '-':
      result = sub(a, b);
      break;

    case '*':
      result = mul(a, b);
      break;

    case '/':
      result = quot(a, b);
      break;

    case '%':
      result = rem(a, b);
      break;

    case '^':
      result = power(a, b);
      break;

    default:
      return 0;
  }

  return result;
}


int is_valid_operation(char c) {
  switch(c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
      return 1;

    default:
      return 0;
  }
}


int main(int argc, char **argv) {
  int a, b;
  char c;

  a = get_integer();
  b = get_integer();
  do {
    printf("Please enter an operation symbol (one of '+', '-', '*', '/', '%%' or '^'): ");
    do {
      scanf("%c", &c);
    } while (c == '\n');
  } while (!is_valid_operation(c));

  printf("%d %c %d = %d.\n", a, c, b, operation(c, a, b));

  return 0;
}
