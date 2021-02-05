#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(int argc, char **argv) {
  double amountDollars;
  int amountCents;
  int numTwenties;
  int numTens;
  int numFives;
  int numDollars;
  int numQuarters;
  int numDimes;
  int numNickels;
  int numPennies;

  /* Ask the user to enter an amount in dollars */
  printf("Please enter a dollar amount: ");
  scanf("%lf", &amountDollars);

  /* Deduce the amount in cents, i.e. $1.23 = 123 cents */
  amountCents = (int) ((amountDollars * 100.0) + 0.5);

  /* Deduce the number of Bills */

  numTwenties = amountCents / 2000;
  amountCents = amountCents - (numTwenties * 2000);

  numTens = amountCents / 1000;
  amountCents = amountCents - (numTens * 1000);

  numFives = amountCents / 500;
  amountCents = amountCents - (numFives * 500);

  numDollars = amountCents / 100;
  amountCents = amountCents - (numDollars * 100);

  numQuarters = amountCents / 25;
  amountCents = amountCents - (numQuarters * 25);

  numDimes = amountCents / 10;
  amountCents = amountCents - (numDimes * 10);

  numNickels = amountCents / 5;
  amountCents = amountCents - (numNickels * 5);

  numPennies = amountCents;


  /* Display the cash */
  printf("$%lf is %d $20 bills, %d $10 bills, %d $5 bills, %d $1 bills, %d quarters, %d dimes, %d nickels and %d pennies.\n",
	 amountDollars,
	 numTwenties,
	 numTens,
	 numFives,
	 numDollars,
	 numQuarters,
	 numDimes,
	 numNickels,
	 numPennies);

  return 0;
}
