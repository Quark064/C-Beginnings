/* William Anderson - 2/26/2021 - C Homework */
#include <stdio.h>

/* A simple power function that takes a base and a power (ints) and returns the (base^power) */
int power(int base, int pow) {
  int i, j = base;

  /* Check if we somehow got an extranious case and provide a correct answer */
  if (pow == 0) {
    return 1;
  }
  if (base == 0) {
    return 0;
  }

  /* Main power loop, calculates 'base' to the power of 'pow' (both integers).
     Assumes that we don't have an extranious case (base, pow >= 1). */
  for (i = 0; i < (pow-1); i++) {
    j = j * base;
  }
  return j;
}

int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char str[BUF_LEN];
  char c;
  int i, binLen, n = 0, is_binary = 1;

  /* Get the user to enter a string */
  printf("Please enter a string made of 0s and 1s, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str[i] = c;
  }
  str[i] = '\0';

  /* Check if the user string contains nothing but 0s and 1s */
  i = 0;
  while (str[i] != '\0') {
    if ((str[i] != '0') && (str[i] != '1')) {
      is_binary = 0;
      break;
    }
    i += 1;
  }
  binLen = i;

  /* Proceed only of the string contains only 0s and 1s */
  if (is_binary) {
    /* Convert the string of 0s and 1s to an integer number n.
       Skips if str[i] == 0, since 0 * pow is always 0, so we don't need to
       run the inefficient power loop more than needed.*/
    for (i = 0; i < binLen; i++) {
      if (str[i] == '1') {
        n += power(2, (binLen - i - 1));
      }
    }

    printf("The binary number %s is %d in decimal.\n", str, n);
  } else {
    printf("The string you entered, \"%s\", contains characters other than 0 and 1.\n", str);
  }

  return 0;
}
