/* William Anderson - 3/5/2021 - C Lab */
#include <stdio.h>

int main(int argc, char **argv) {
  const int BUF_LEN = 4095;
  char num_str1[BUF_LEN];
  char num_str2[BUF_LEN];
  char num_str3[BUF_LEN + 1];
  char c;
  int i;
  int alldigits;
  int num_str1_len, num_str2_len, num_str3_len;
  int idx1, idx2, idx3;
  int d1, d2, d3;
  int carry = 0, append = 0;
  char tmp;

  /* Get the user to enter two strings */
  printf("Please enter a string made of decimal digits 0 through 9, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    num_str1[i] = c;
  }
  num_str1[i] = '\0';

  printf("Please enter a string made of decimal digits 0 through 9, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    num_str2[i] = c;
  }
  num_str2[i] = '\0';


  for (i = 0; (num_str1[i] != '\0') && (i < BUF_LEN); i++) {
    if ((num_str1[i] < '0') || (num_str1[i] > '9')) {
      alldigits = 0;
      break;
    }
  }
  num_str1_len = i-1;
  for (i = 0; (num_str2[i] != '\0') && (i < BUF_LEN) && (alldigits); i++) {
    if ((num_str2[i] < '0') || (num_str2[i] > '9')) {
      alldigits = 0;
      break;
    }
  }
  num_str2_len = i-1;


  if (alldigits && (num_str1[0] != '\0') && (num_str2[0] != '\0')) {
    idx1 = num_str1_len;
    idx2 = num_str2_len;
    idx3 = 0;

    while(idx1 >= 0 || idx2 >= 0) {
      d1 = (idx1 >= 0) ? (num_str1[idx1] - '0') : 0;
      d2 = (idx2 >= 0) ? (num_str2[idx2] - '0') : 0;
      d3 = d1 + d2 + carry;

      append = (d3 % 10);
      num_str3[idx3] = (append) + '0';
      carry = (d3 > 9) ? 1 : 0;

      idx1--;
      idx2--;
      idx3++;
    }

    if (carry + '0' != '0'){
      num_str3[idx3++] = carry + '0';
  }

    num_str3[idx3--] = '\0';
    num_str3_len = idx3;

    for (i = 0; i < ((num_str3_len / 2) + 1); i++) {
      tmp = num_str3[i];
      num_str3[i] = num_str3[num_str3_len-i];
      num_str3[num_str3_len-i] = tmp;
    }

    printf("%s + %s = %s\n", num_str1, num_str2, num_str3);

  } else {
    printf("One of the strings you entered, \"%s\" or \"%s\", contains a character that is not a digit 0 through 9 or one of the strings is empty.\n",
	   num_str1, num_str2);
  }

  return 0;
}
