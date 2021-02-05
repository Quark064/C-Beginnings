#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  int arr[7];
  int min, max, store = 0;
  double avg;

  /* Get user inputs */
  for (i = 0; i < 8; i++){
    printf("Please enter int variable #%d: ", (i+1));
    scanf("%d", &arr[i]);
    printf("\n");
  }

  /* Calculate Min Max and Avg */
  for (i = 0; i < 8; i++){
    if (arr[i] > max){
      max = arr[i];
    }
  }

  for (i = 0; i < 8; i++){
    if (arr[i] < min){
      min = arr[i];
    }
  }

  for (i = 0; i < 8; i++){
    store = store + arr[i];
  }

  avg = (store / 8.0);

  /* Print results */
  printf("min(");
  for (i = 0; i < 8; i++){
    if (i < 7){
      printf("%d, ", arr[i]);
    }
    else {
      printf("%d)", arr[i]);
    }
  }
  printf(" = %d\n", min);

  printf("max(");
  for (i = 0; i < 8; i++){
    if (i < 7){
      printf("%d, ", arr[i]);
    }
    else {
      printf("%d)", arr[i]);
    }
  }
  printf(" = %d\n", max);

  printf("avg(");
  for (i = 0; i < 8; i++){
    if (i < 7){
      printf("%d, ", arr[i]);
    }
    else {
      printf("%d)", arr[i]);
    }
  }
  printf(" = %lf\n", avg);

  return 0;
}
