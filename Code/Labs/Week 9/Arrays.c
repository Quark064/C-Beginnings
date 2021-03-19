/* William Anderson - 3/19/2021 - C Lab */
#include <stdio.h>
#include <math.h>


double get_real() {
  double userIn;

  printf("Please enter a real number: ");
  scanf("%lf", &userIn);

  return userIn;
}

double squared(double x) {
  return (x * x);
}

double absolute_value(double x) {
  if (x >= 0) {
    return x;
  }

  return (x * -1);
}


void print_array(double array[], int n) {
  int i;

  if (n <= 0) {
    printf("\n");
  }
  else {
    for (i = 0; i < n; i++) {
      if (i != n-1) {
        printf("%lf, ", array[i]);
      }
      else {
        printf("%lf\n", array[i]);
      }
    }
  }
}


int index_of_minimum(double array[], int n) {
  int i;
  int mini = 0;

  if (n <= 0) {
    return 0;
  }

  for (i = 1; i < n; i++) {
    if (array[mini] > array[i]) {
      mini = i;
    }
  }

  return mini;
}


int index_of_maximum(double array[], int n) {
  int i;
  int max = 0;

  if (n <= 0) {
    return 0;
  }

  for (i = 1; i < n; i++) {
    if (array[max] < array[i]) {
      max = i;
    }
  }

  return max;
}


int index_of_smallest(double array[], int n) {
  int i;
  int index = 0;

  if (n <= 0) {
    return 0;
  }

  for (i = 1; i < n; i++) {
    if (absolute_value(array[index]) > absolute_value(array[i])) {
      index = i;
    }
  }

  return index;
}


int index_of_largest(double array[], int n) {
  int i;
  int index = 0;

  if (n <= 0) {
    return 0;
  }

  for (i = 1; i < n; i++) {
    if (absolute_value(array[index]) < absolute_value(array[i])) {
      index = i;
    }
  }

  return index;
}


double minimum(double array[], int n) {
  if (n <= 0) {
    return 0;
  }

  return array[index_of_minimum(array, n)];
}


double maximum(double array[], int n) {
  if (n <= 0) {
    return 0;
  }

  return array[index_of_maximum(array, n)];
}


double smallest(double array[], int n) {
  if (n <= 0) {
    return 0;
  }

  return array[index_of_smallest(array, n)];
}


double largest(double array[], int n) {
  if (n <= 0) {
    return 0;
  }

  return array[index_of_largest(array, n)];
}


double average(double array[], int n) {
  int i;
  double count = 0.0;

  if (n <= 0) {
    return 0;
  }

  for (i = 0; i < n; i++) {
    count += array[i];
  }

  return count / n;
}


double variance(double array[], int n) {
  double avg = average(array, n);
  double vari = 0.0;
  int i;

  for (i = 0; i < n; i++) {
    vari += squared((array[i] - avg));
  }

  return vari / n;
}


double standard_deviation(double array[], int n) {
  return sqrt(variance(array, n));
}


/* A main() to try everything out. */
int main(int argc, char **argv) {
  const int NUM_ELEMENTS = 16;
  double values[NUM_ELEMENTS];
  int i;

  /* Get user input */
  printf("Please enter %d values.\n", NUM_ELEMENTS);
  for (i=0; i<NUM_ELEMENTS; i++) {
    values[i] = get_real();
  }

  /* Print out the array */
  print_array(values, NUM_ELEMENTS);

  /* Print statistics */
  printf("The minimum  value is %lf and it is located at element #%d.\n", minimum(values, NUM_ELEMENTS), index_of_minimum(values, NUM_ELEMENTS) + 1);
  printf("The maximum  value is %lf and it is located at element #%d.\n", maximum(values, NUM_ELEMENTS), index_of_maximum(values, NUM_ELEMENTS) + 1);
  printf("The smallest value is %lf and it is located at element #%d.\n", smallest(values, NUM_ELEMENTS), index_of_smallest(values, NUM_ELEMENTS) + 1);
  printf("The largest  value is %lf and it is located at element #%d.\n", largest(values, NUM_ELEMENTS), index_of_largest(values, NUM_ELEMENTS) + 1);
  printf("The average value  is %lf.\n", average(values, NUM_ELEMENTS));
  printf("The variance is %lf and the standard deviation is %lf.\n", variance(values, NUM_ELEMENTS), standard_deviation(values, NUM_ELEMENTS));

  return 0;
}
