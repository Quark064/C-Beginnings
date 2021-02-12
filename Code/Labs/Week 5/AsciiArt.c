/* William Anderson - 2/12/2021 - C Lab */
#include <stdio.h>

int main(int argc, char const *argv[]) {
  char asciiChar = '*';
  int j, k, i = 1, userIn = 1;

  /* Get a valid user input */
  while (i) {
    printf("Enter a positive integer: ");
    scanf("%d", &userIn);
    if (userIn > 0){
      break;
    }
    printf("\nThis number can't be negative/zero or is invalid! Try again...\n\n");
  }

  /* Print the solid square */
  printf("\n");
  for (i = 0; i < userIn; i++) {
    for (j = 0; j < userIn; j++){
      printf("%c", asciiChar);
    }
    printf("\n");
  }

  /* Print the empty square */
  printf("\n");
  for (i = 0; i < userIn; i++) {
    if ((i == 0) || (i == (userIn - 1))) {
      for (j = 0; j < userIn; j++) {
        printf("%c", asciiChar);
      }
    } else {
      for (j = 0; j < userIn; j++) {
        if ((j == 0) || (j == (userIn - 1))){
          printf("%c", asciiChar);
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }

  /* Print the cascading triangle shape */
  printf("\n");
  for (i = 0; i < userIn; i++) {
    for (k = 0; k < (i + 1); k++) {
      printf(" ");
    }
    for (k = k; k < userIn; k++) {
      printf("%c", asciiChar);
    }
    printf("\n");
  }

  return 0;
}
