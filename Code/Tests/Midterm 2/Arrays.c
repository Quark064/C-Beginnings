
/* Program for statistics

   (C) 2021 University of Alaska Anchorage

   Written by  Chr. Lauter          and

              William Anderson

*/

#include <stdio.h>

double get_real() {
  double userIn;

  printf("Please enter a real number: ");
  scanf("%lf", &userIn);

  return userIn;
}


void print_array(double array[], int n) {
  int i;

  if (n == 0) {
    printf("[]\n");
  }
  else if (n >= 1) {
    printf("[");
    for (i = 0; i < n; i++) {
      if (i != n-1) {
        printf("%lf, ", array[i]);
      }
      else {
        printf("%lf]\n", array[i]);
      }
    }
  }
}

/*
   NOTE: RENAMED 'average' TO 'get_average' SINCE THE COMPILER WAS LOOKING FOR
   A BUILT-IN AVERAGE FUNCTION RATHER THAN THE USER DEFINED ONE FOR SOME REASON
*/

double get_average(double array[], int n) {
  int i;
  double count = 0.0;

  if (n <= 0) {
    return 0.0;
  }

  for (i = 0; i < n; i++) {
    count += array[i];
  }

  return count / n;
}


double absolute_value(double x) {
  if (x >= 0.0) {
    return x;
  }

  return (x * -1);
}


int index_of_closest_to_average(double values[], int n) {
  double average;
  int index;
  int i;

  if (n <= 0) {
    return -1;
  }

  average = get_average(values, n);

  index = 0;
  for (i = 1; i < n; i++) {
    if (absolute_value((average - values[index])) > absolute_value((average - values[i]))) {
      index = i;
    }
  }

  return index;
}


int main(int argc, char **argv) {
  const int NUM_ELEMENTS = 16;
  double array[NUM_ELEMENTS];
  int i, idx;

  printf("Please enter %d real numbers.\n", NUM_ELEMENTS);
  for (i=0; i<NUM_ELEMENTS; i++) {
    array[i] = get_real();
  }

  printf("The array you entered is:\n");
  print_array(array, NUM_ELEMENTS);

  printf("The average value is %lf.\n", get_average(array, NUM_ELEMENTS));
  idx = index_of_closest_to_average(array, NUM_ELEMENTS);
  if ((0 <= idx) && (idx <= NUM_ELEMENTS - 1)) {
    printf("The value closest to the average is value #%d. Its value is %lf.\n", idx + 1, array[idx]);
  }

  return 0;
}
