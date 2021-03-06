/* William Anderson - 3/5/2021 - C Lab */

#include <stdio.h>

int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char haystack[BUF_LEN];
  char needle[BUF_LEN];
  char c;
  int i = 0, j = 0, substring = 1, found = 0;
  int needle_len, haystack_len;

  /* Get the user to enter two strings */
  printf("Please enter a string, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    needle[i] = c;
  }
  needle[i] = '\0';

  printf("Please enter another string, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    haystack[i] = c;
  }
  haystack[i] = '\0';

  /* Print the string once */
  printf("The strings you entered are \"%s\" and \"%s\".\n", needle, haystack);

  for (needle_len = 0; (needle[needle_len] != '\0') && (needle_len < BUF_LEN); needle_len++);
  for (haystack_len = 0; (haystack[haystack_len] != '\0') && (haystack_len < BUF_LEN); haystack_len++);

  if (needle_len > haystack_len) {
    substring = 0;
    found = 1;
  }
  if (needle_len == 0) {
    substring = 1;
    found = 1;
  }

   while (!found) {
     for (i = 0; i < haystack_len; i++) {
       if (j == needle_len) {
         break;
       }

       if (haystack[i] == needle[0]) {
         for (j = 0; j < needle_len; j++) {
           if (haystack[i+j] != needle[j]) {
             found = 0;
             break;
           }
           found = 1;
         }
       }
     }

     if (!found) {
       substring = 0;
       found = 1;
     }
   }

  /* Print the answer */
  if (substring) {
    printf("\"%s\" is contained as a substring in \"%s\".\n", needle, haystack);
  } else {
    printf("\"%s\" is not contained as a substring in \"%s\".\n", needle, haystack);
  }

  return 0;
}
