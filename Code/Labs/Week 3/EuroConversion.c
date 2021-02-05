#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char const *argv[]) {
  char userIn, *defaultBill, *billCoin;
  char *dollCoinArr[4], *dollBillsCheck[8], *euroBillsCheck[12];
  int euroArr[] = {50, 20, 10, 5, 2, 1};
  int dollArr[] = {20, 10, 5, 1};
  int euroToCentArr[] = {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int dollToCentArr[] = {2000, 1000, 500, 100, 25, 10, 5, 1};
  int euroValArr[12], dollValArr[8], amountDollValArr[8], amountEuroValArr[12];
  unsigned int i = 0, totalDollCents = 0, totalEuroCents = 0, convCents = 0;

  printf("Please choose the conversion direction: E for Euro->US Dollar, any "
         "other letter US Dollar->Euro: ");
  scanf("%s", &userIn);

  if (userIn == 69) {
    defaultBill = "Euro";

    for (i = 0; i < 6; i++) {
      billCoin = (i < 4) ? "bills" : "coins";
      printf("Please enter the number of %s %d %s: ", defaultBill, euroArr[i],
             billCoin);
      scanf("%d", &amountEuroValArr[i]);
    }
    for (i = 0; i < 6; i++) {
      billCoin = (i < 5) ? "cents" : "cent";
      printf("Please enter the number of %s %d %s coins: ", defaultBill,
             euroArr[i], billCoin);
      scanf("%d", &amountEuroValArr[(i + 6)]);
    }

    for (i = 0; i < 12; i++) {
      totalEuroCents =
          totalEuroCents + (amountEuroValArr[i] * euroToCentArr[i]);
    }

    totalDollCents = (totalEuroCents * 121199) / 100000;

  }

  else {
    defaultBill = "Dollar";
    for (i = 0; i < 8; i++) {
      printf("Please enter the number of ");

      if (i < 4) {
        printf("%s %d bills: ", defaultBill, dollArr[i]);
        scanf("%d", &amountDollValArr[i]);
      } else {
        dollCoinArr[0] = "quarters";
        dollCoinArr[1] = "dimes";
        dollCoinArr[2] = "nickles";
        dollCoinArr[3] = "pennies";

        printf("%s: ", dollCoinArr[(i - 4)]);
        scanf("%d", &amountDollValArr[i]);
      }
    }

    for (i = 0; i < 8; i++) {
      totalDollCents =
          totalDollCents + (amountDollValArr[i] * dollToCentArr[i]);
    }

    totalEuroCents = (totalDollCents * 100000) / 121199;
  }

  for (i = 0; i < 12; i++) {
    euroValArr[i] = (totalEuroCents / euroToCentArr[i]);
    totalEuroCents = totalEuroCents % euroToCentArr[i];
  }

  for (i = 0; i < 8; i++) {
    dollValArr[i] = (totalDollCents / dollToCentArr[i]);
    totalDollCents = totalDollCents % dollToCentArr[i];
  }

  for (i = 0; i < 12; i++) {
    euroBillsCheck[i] = (euroValArr[i] == 1) ? "" : "s";
  }

  for (i = 0; i < 8; i++) {
    dollBillsCheck[i] = (dollValArr[i] == 1) ? "" : "s";
  }

  dollBillsCheck[7] = (dollValArr[7] == 1) ? "y" : "ies";

  if (userIn == 69) {
    printf(
        "\n\n%d $20 bill%s, %d $10 bill%s, %d $5 bill%s, %d $1 bill%s, %d "
        "quarter%s, %d dime%s, %d nickel%s and %d penn%s\n\nCorresponds to:\n",
        dollValArr[0], dollBillsCheck[0], dollValArr[1], dollBillsCheck[1],
        dollValArr[2], dollBillsCheck[2], dollValArr[3], dollBillsCheck[3],
        dollValArr[4], dollBillsCheck[4], dollValArr[5], dollBillsCheck[5],
        dollValArr[6], dollBillsCheck[6], dollValArr[7], dollBillsCheck[7]);
    printf("\n%d (Euro)50 bill%s, %d (Euro)20 bill%s, %d (Euro)10 bill%s, 1%d "
           "(Euro)5 bill%s, %d (Euro)2 coin%s, %d (Euro)1 coin%s, %d "
           "50(Euro)cents coin%s,\n%d 20(Euro)cents coin%s, %d 10(Euro)cents "
           "coin%s, %d 5(Euro)cents coin%s, %d 2(Euro)cents coin%s and %d "
           "1(Euro)cent coin%s.\n",
           amountEuroValArr[0], euroBillsCheck[0], amountEuroValArr[1],
           euroBillsCheck[1], amountEuroValArr[2], euroBillsCheck[2],
           amountEuroValArr[3], euroBillsCheck[3], amountEuroValArr[4],
           euroBillsCheck[4], amountEuroValArr[5], euroBillsCheck[5],
           amountEuroValArr[6], euroBillsCheck[6], amountEuroValArr[7],
           euroBillsCheck[7], amountEuroValArr[8], euroBillsCheck[8],
           amountEuroValArr[9], euroBillsCheck[9], amountEuroValArr[10],
           euroBillsCheck[10], amountEuroValArr[11], euroBillsCheck[11]);
  } else {
    printf(
        "\n\n%d $20 bill%s, %d $10 bill%s, %d $5 bill%s, %d $1 bill%s, %d "
        "quarter%s, %d dime%s, %d nickel%s and %d penn%s\n\nCorresponds to:\n",
        amountDollValArr[0], dollBillsCheck[0], amountDollValArr[1],
        dollBillsCheck[1], amountDollValArr[2], dollBillsCheck[2],
        amountDollValArr[3], dollBillsCheck[3], amountDollValArr[4],
        dollBillsCheck[4], amountDollValArr[5], dollBillsCheck[5],
        amountDollValArr[6], dollBillsCheck[6], amountDollValArr[7],
        dollBillsCheck[7]);
    printf("\n%d (Euro)50 bill%s, %d (Euro)20 bill%s, %d (Euro)10 bill%s, 1%d "
           "(Euro)5 bill%s, %d (Euro)2 coin%s, %d (Euro)1 coin%s, %d "
           "50(Euro)cents coin%s,\n%d 20(Euro)cents coin%s, %d 10(Euro)cents "
           "coin%s, %d 5(Euro)cents coin%s, %d 2(Euro)cents coin%s and %d "
           "1(Euro)cent coin%s.\n",
           euroValArr[0], euroBillsCheck[0], euroValArr[1], euroBillsCheck[1],
           euroValArr[2], euroBillsCheck[2], euroValArr[3], euroBillsCheck[3],
           euroValArr[4], euroBillsCheck[4], euroValArr[5], euroBillsCheck[5],
           euroValArr[6], euroBillsCheck[6], euroValArr[7], euroBillsCheck[7],
           euroValArr[8], euroBillsCheck[8], euroValArr[9], euroBillsCheck[9],
           euroValArr[10], euroBillsCheck[10], euroValArr[11],
           euroBillsCheck[11]);
  }
  return 0;
}
