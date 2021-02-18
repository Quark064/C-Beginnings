/* William Anderson - 2/18/2021 - C Midterm */

#include <stdio.h>

int main(int argc, char **argv) {
  int userNum, i, j, verify = 0;

  while (verify == 0) {
    printf("Please enter a number between 1 and 18 (both included): ");
    scanf("%d", &userNum);

    verify = ((userNum <= 18) && (userNum >= 1)) ? 1 : 0;
  }
  printf("\n\n");


  for (i = 1; i <= (userNum); ++i) {
    if (i % 2) {
      for (j = 0; j <= (userNum - i) ; ++j) {
        printf(" ");
      }
      for (j = 0; j <= ((i * 2) - 2); ++j) {
        printf("*");
      }
      printf("\n");
    }


    else {
      for (j = 0; j <= (userNum - 2); ++j) {
        printf(" ");
      }
      printf("***\n");
    }

}






  return 0;
}
