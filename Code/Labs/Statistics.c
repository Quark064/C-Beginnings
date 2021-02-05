/* William Anderson - 2/5/2021 - C Lab */
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int min, max, userIn, tick = 1, count = 0;
  double avg;

  while (userIn >= 0) {
    printf("Enter integer %d (Enter negative int to stop): ", tick);
    scanf("%d", &userIn);

    if (tick == 1) {
      min = userIn;
      max = userIn;
    }

    if (userIn < 0) {
      if (tick == 1) {
        printf("No values entered, program will now terminate.\n");
        return 0;
      }
      break;
    }

    if (userIn < min) {
      min = userIn;
    }

    if (userIn > max) {
      max = userIn;
    }

    count += userIn;
    tick += 1;
  }

  printf("Minimum of non-negative values: %d\nMaximum of non-negative values: "
         "%d\nAverage of non-neative values: %lf\n",
         min, max, ((float)count / (tick - 1)));

  return 0;
}
