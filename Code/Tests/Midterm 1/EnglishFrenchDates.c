/* William Anderson - 2/18/2021 - C Midterm */
#include <stdio.h>

int main(int argc, char **argv) {
  int year, month, day, leapyear, validdate = 0, checkSuffix;
  char months[12][10] = {"January",   "Feburary", "March",    "April",
                        "May",       "June",     "July",     "August",
                        "September", "October",  "November", "December"};
  char frenchMonths[12][10] = {"janvier", "fevrier", "mars", "avril", "mai",
                              "juin", "juillet", "aout", "septembre", "octobre",
                              "novembre", "decembre"};


  while (validdate == 0) {

    /* Have the user enter a date */
    printf("Please enter a month (1 - 12): ");
    scanf("%d", &month);
    printf("Please enter a day (1 - 31): ");
    scanf("%d", &day);
    printf("Please enter a year (1600 - 2400): ");
    scanf("%d", &year);

    leapyear = (((year % 400 == 0) || (year % 4 == 0)) && (year % 100 != 0));
    validdate = ((month >= 1) && (month <= 12)) && ((year >= 1600) && (year <= 2400));

    if (validdate) {
      switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
          validdate = (day <= 31);
          break;

        case 2:
          validdate = (leapyear) ? (day <= 29) : (day <= 28);
          break;

        default:
          validdate = (day <= 30);
          break;
      }
    }

      if (validdate) {
        checkSuffix = (day % 10);
        printf("%s %d%s %d\n", months[month - 1], day, (
               ((checkSuffix == 1) && (day != 11)) ? "st" :
               ((checkSuffix == 2) && (day != 12)) ? "nd" :
               ((checkSuffix == 3) && (day != 13)) ? "rd" : "th"),
               year);

        if (day == 1) {
          printf("ler %s %d\n", frenchMonths[month - 1], year);
        } else {
          printf("%d %s %d\n", day, frenchMonths[month - 1], year);
        }

      } else {
        printf("Invalid information entered. Please try again...\n");
      }
  }

  return 0;
}
