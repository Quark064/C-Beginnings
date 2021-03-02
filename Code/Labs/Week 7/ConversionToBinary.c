/* William Anderson - 2/26/2021 - C Homework */
#include <stdio.h>

int main(int argc, char **argv) {
  int n, k, i, l = 0;
  char tmp;
  char str[65];

  /* Make the user enter a non-negative integer */
  printf("Please enter a non-negative integer: ");
  scanf("%d", &n);
  while (n < 0) {
    printf("Sorry, your input is incorrect.\n");
    printf("Please enter a non-negative integer: ");
    scanf("%d", &n);
  }

  /* Convert the integer to reversed binary: e.g. 6 gets converted to 011 */
  if (n == 0) {
    /* Special case for n = 0 */
    str[0] = '0';
    str[1] = '\0';
  } else {

    k = n;

    i = 0;
    while (k > 0) {
      str[i] = ((k % 2) ? '1' : '0');
      k = k / 2;
      i += 1;
    }
    str[i] = '\0';
    l = i - 1;
  }

/* Reverse the string */
  for (i = 0; i < ((l / 2) + 1); i++) {
    tmp = str[i];
    str[i] = str[l-i];
    str[l-i] = tmp;
  }

  /* Display the number and the string */
  printf("The decimal number %d is %s in binary.\n", n, str);

  return 0;
}
