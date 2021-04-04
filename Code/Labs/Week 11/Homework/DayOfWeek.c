/* William Anderson - 4/2/2021 - C Homework */
#include <stdio.h>

int isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 1;
  return 0;
}

int getCenturyValue(int year) {
  return (2 * (3 - ((year / 100) % 4)));
}

int getYearValue(int year) {
  int y;

  y = year % 100;
  return ((y / 4) + y);
}

int getMonthValue(int month, int year) {
  int leapYearArr[12] = {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
  int noLeapYearArr[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

  if (isLeapYear(year)) {
    return leapYearArr[month-1];
  }
  else {
    return noLeapYearArr[month-1];
  }
}

int dayOfWeekNumber(int day, int month, int year) {
  return ((getCenturyValue(year) + getYearValue(year) + getMonthValue(month, year) + day) % 7);
}

const char *dayOfWeek(int day, int month, int year) {
  int dayNumber = dayOfWeekNumber(day, month, year);

  switch(dayNumber) {
    case 0:
      return "Sunday";
    case 1:
      return "Monday";
      break;
    case 2:
      return "Tuesday";
      break;
    case 3:
      return "Wednesday";
      break;
    case 4:
      return "Thursday";
      break;
    case 5:
      return "Friday";
      break;
    case 6:
      return "Saturday";
      break;

    default:
      return "[ERROR: DAY OUT OF RANGE 0-6]";
      break;
  }
}

int getInput(char type);
int verifiedNumber(char type, int boundA, int boundB, const char *message) {
  int returnedValue;

  printf("%s", message);
  scanf("%d", &returnedValue);

  if ((returnedValue < boundA || returnedValue > boundB)) {
    printf("Sorry, that's not a valid input..\n\n");
    return getInput(type);
  }
  else return returnedValue;
}

int getInput(char type) {
  switch(type) {
    case 'D':
      return verifiedNumber('D', 1, 31, "Please enter a day (as a number): ");
      break;

    case 'M':
      return verifiedNumber('M', 1, 12, "Please enter a month (as a number): ");
      break;

    case 'Y':
      return verifiedNumber('Y', 1, 9999, "Please enter a year: ");
      break;

    default:
      return 0;
      break;
  }
}

int finalCheck(int day, int month, int year) {
  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (isLeapYear(year)) {
    daysInMonth[1] = 29;
  }

  if (day <= daysInMonth[month-1]) {
    return 1;
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  int day = getInput('D');
  int month = getInput('M');
  int year = getInput('Y');

  if (finalCheck(day, month, year)) {
    printf("%d-%d-%d is a %s.\n", year, month, day, dayOfWeek(day, month, year));
  }
  else {
    printf("Sorry, that's not a valid combination..");
  }

  return 0;
}
