/* William Anderson - 3/26/2021 - C Lab */
#include <stdio.h>


int string_len(char str[]) {
  int i;

  for (i = 0; str[i] != '\0'; i++);

  return i;
}


int string_is_palindrome(char str[]) {
  int i = 0;
  int j = string_len(str) - 1;

  while (i < j) {
    if (str[i] != str[j]) {
      return 0;
    }
    i++;
    j--;
  }

  return 1;
}


int string_character_index(char str[], char c) {
  int i;

  for (i = 0; (str[i] != c) && (str[i] != '\0'); i++);

  if (str[i] == '\0') {
    return -1;
  }
  else {
    return i;
  }
}


int string_character_index_reverse(char str[], char c) {
  int len;

  for (len = (string_len(str) - 1); (len >= -1) && (str[len] != c); len--);

  if (len < 0) {
    return -1;
  }
  else {
    return len;
  }
}


int string_common_characters(char str1[], char str2[]) {
  int i;

  for (i = 0; str1[i] != '\0'; i++) {
    if (string_character_index(str2, str1[i]) != -1) {
      return 1;
    }
  }

  return 0;
}

int contains_within_bound(char str[], char boundA, char boundB) {
  int i;

  for (i = 0; str[i] != '\0'; i++) {
    if ((str[i] >= boundA) && (str[i] <= boundB)) {
      return 1;
    }
  }

  return 0;
}


int string_contains_uppercase(char str[]) {
  return contains_within_bound(str, 'A', 'Z');
}


int string_contains_lowercase(char str[]) {
  return contains_within_bound(str, 'a', 'z');
}


int string_contains_digit(char str[]) {
  return contains_within_bound(str, '0', '9');
}


int string_is_valid_password(char str[]) {
  int valid = 0;
  char specialChars[28] = {'+', '=', '-', '*', '/', '%', '^', '&', '~', '#', '{', '[', '|', '\\', '@', ']', '}', '$', '!', ':', ';', ',', ',', '.', '<', '>', '(', ')'};

  valid = (string_contains_uppercase(str) && string_contains_lowercase(str) && string_contains_digit(str) && string_common_characters(str, specialChars));
  return valid;
}


/* A main() to test the functions defined above.

   No modification is needed here.

*/
int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char str[BUF_LEN];
  char c;
  int i;

  /* Get the user to enter a string */
  printf("Please enter a string, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str[i] = c;
  }
  str[i] = '\0';

  /* Get the user to enter a character */
  printf("Please enter a character: ");
  do {
    scanf("%c", &c);
  } while (c == '\0');

  /* Print the string and the character */
  printf("The string you entered is \"%s\" and the character you entered is \'%c\'.\n", str, c);

  /* Exercise the functions above */
  printf("The length of the string \"%s\" is %d.\n", str, string_len(str));
  printf("The string \"%s\" is a palindrome: %s.\n", str, ((string_is_palindrome(str)) ? "yes" : "no"));
  printf("The character \'%c\' can be found in the string \"%s\" the first time (first from the left) at index %d.\n", c, str, string_character_index(str, c));
  printf("The character \'%c\' can be found in the string \"%s\" the last time  (first from the right) at index %d.\n", c, str, string_character_index_reverse(str, c));
  printf("The string \"%s\" and the string \"Hello world\" have common characters: %s.\n", str, ((string_common_characters(str, "Hello world")) ? "yes" : "no"));
  printf("The string \"%s\" contains upper-case letters: %s.\n", str, ((string_contains_uppercase(str)) ? "yes" : "no"));
  printf("The string \"%s\" contains lower-case letters: %s.\n", str, ((string_contains_lowercase(str)) ? "yes" : "no"));
  printf("The string \"%s\" contains digits: %s.\n", str, ((string_contains_digit(str)) ? "yes" : "no"));
  printf("The string \"%s\" is a valid password: %s.\n", str, ((string_is_valid_password(str)) ? "yes" : "no"));

  return 0;
}
