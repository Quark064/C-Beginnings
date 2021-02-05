#include <stdio.h>

int main(int argc, char const *argv[]) {
  double degF;
  double degC;

  printf("Please Enter Temp (F): ");
  scanf("%lf", &degF);

  degC = (degF - 32.0) * (5.0/9.0);
  printf("\n%.2lf F is equal to %.2lf C.", degF, degC);


  return 0;
}
