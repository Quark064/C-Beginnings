#include <stdio.h>

int inches;

int checkDis(int convType) {
  int disCheck;

  disCheck = inches / convType;
  inches = inches - (disCheck * convType);

  return disCheck;
  }

int main(int argc, char const *argv[]) {
    const int inchMile = 63360;
    const int inchYard = 36;
    const int inchFeet = 12;
    int numMM;
    int miles;
    int yards;
    int feet;

    printf("Enter number of mm: ");
    scanf("%d", &numMM);

    inches = (numMM * 10) / 254;   /* Convert mm to inch */

    miles = checkDis(inchMile);
    yards = checkDis(inchYard);
    feet = checkDis(inchFeet);

    printf("\n%d mm is equal to:\n%d miles\n%d yards\n%d feet\n%d inches",
          numMM, miles, yards, feet, inches);


  return 0;
}
