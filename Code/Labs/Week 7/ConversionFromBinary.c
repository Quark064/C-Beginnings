/* William Anderson - 2/26/2021 - C Homework */
#include <stdio.h>

int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char str[BUF_LEN];
  char c;
  int i, binLen;
  int power = 1, n = 0, is_binary = 1;

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
    /* Convert the string of 0s and 1s to an integer number n. */
    for (i = binLen-1; i >= 0; i--) {
      if (str[i] == '1') {
        n += power;
      }
      power = power * 2;
    }

    printf("The binary number %s is %d in decimal.\n", str, n);
  } else {
    printf("The string you entered, \"%s\", contains characters other than 0 and 1.\n", str);
  }

  return 0;
}
