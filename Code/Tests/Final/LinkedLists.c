/* Program for linked lists.

   (C) 2020-21 UAA

   Program written by Chr. Lauter.

   Program modified and completed by

   William Anderson

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Each function you need to work on is clearly marked with

   TODO

   The difficulty of each function is marked with each function.

   The points you can get for each function is marked with each
   function.

   The sum of possible points in this file is 126.

   Students get an A for 90 points or better.

*/


/* A typedef for a linked list of strings

   No changes are needed here.

*/
struct __list_struct_t {
  char                   *str;
  struct __list_struct_t *next;
};
typedef struct __list_struct_t list_t;


/* Function to call in case malloc or calloc cannot allocate new
   memory because no memory is left.

   No changes are needed here.

   THIS FUNCTION NEEDS TO BE CALLED IN ALL PLACES WHERE MEMORY IS
   ALLOCATED AND THE ALLOCATION FUNCTION RETURNS NULL BECAUSE NO
   MEMORY IS LEFT.

*/
void error_no_memory_left() {
  fprintf(stderr, "No memory left.\n");
  exit(1);
}


/* Gets input from the user in the form of a string. The string
   contains up to n characters, including the end marker '\0'.

   No changes are needed here.

*/
void input_string(char str[], int n) {
  char c;
  int i;
  int first;

  if (n < 1) return;
  first = 1;
  for (i=0; i<n-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      if (first) {
	first = 0;
	i = -1;
	continue;
      } else {
	break;
      }
    }
    str[i] = c;
    first = 0;
  }
  str[i] = '\0';
}

/* A function to add a string to a linked list

   The function copies the string after allocating enough memory for
   it.

   DIFFICULTY: 2
   POINTS POSSIBLE: 6

*/
list_t *add_to_list(char *str, list_t *list) {
  list_t *newElement;

  newElement = (list_t*) malloc(sizeof(list_t));
  newElement->str = (char*) calloc(strlen(str)+1, sizeof(char));

  if (newElement == NULL || newElement->str == NULL) {
    error_no_memory_left();
  }

  strcpy(newElement->str, str);

  newElement->next = list;

  return newElement;
}


/* Deletes a list by freeing all its memory. Also frees the memory
   taken by the strings in the list.

   DIFFICULTY: 3
   POINTS POSSIBLE: 9

*/
void delete_list(list_t *list) {
  list_t *itter = list;
  list_t *pStore;

  while (itter != NULL) {
    pStore = itter->next;
    free(itter->str);
    free(itter);
    itter = pStore;
  }
}


/* A function to print out a list, each string on one line

   DIFFICULTY: 1
   POINTS POSSIBLE: 3

*/
void print_list(list_t *list) {
  list_t *currentPointer = list;

  if (list == NULL) return;

  do {
    printf("%s\n", currentPointer->str);
    currentPointer = currentPointer->next;
  } while (currentPointer != NULL);
}


/* A function to compute the length of a list

   DIFFICULTY: 1
   POINTS POSSIBLE: 3

*/
int length_list(list_t *list) {
  list_t *currentPointer = list;
  int counter = 1;

  if (list == NULL) return 0;

  while (currentPointer->next != NULL) {
    currentPointer = currentPointer->next;
    counter++;
  }

  return counter;
}


/* A function to revert a list.

   The function recreates a new list. Each string gets copied in
   memory into a newly allocated string.

   DIFFICULTY: 2
   POINTS POSSIBLE: 6

*/
list_t *revert_list(list_t *list) {
  list_t *prev = NULL;
  list_t *current = list;
  list_t *newAddress;
  char *stringStore;

  if (list == NULL) return list;

  for (current = list; current != NULL; current = current->next) {
    stringStore = current->str;

    newAddress = (list_t*) malloc(sizeof(list_t));
    newAddress->str = (char *) calloc(strlen(current->str)+1, sizeof(char));

    if (newAddress == NULL || newAddress->str == NULL) {
      error_no_memory_left();
    }

    strcpy(newAddress->str, stringStore);

    newAddress->next = prev;
    prev = newAddress;
  }

  return newAddress;
}


/* A function to copy a list without reverting it.

   The function recreates a new list. Each string gets copied in
   memory into a newly allocated string.

   This function must not call revert_list. It must not free any
   memory. It needs to copy the list without twice reverting it.

   DIFFICULTY: 4
   POINTS POSSIBLE: 12

*/
list_t *copy_list(list_t *list) {
  list_t *startingPoint;
  list_t *current = NULL;
  list_t *prev = NULL;
  list_t *nodeCrawler;
  int i = 1;

  if (list == NULL) return list;

  for (nodeCrawler = list; nodeCrawler != NULL; nodeCrawler = nodeCrawler->next) {
    current = (list_t*) malloc(sizeof(list_t));
    current->str = (char*) calloc(strlen(nodeCrawler->str)+1, sizeof(char));

    if (current == NULL || current->str == NULL) {
      error_no_memory_left();
    }

    strcpy(current->str, nodeCrawler->str);

    if (i) {
      startingPoint = current;
      i = 0;
    }
    else {
      prev->next = current;
    }
    prev = current;
  }

  current->next = NULL;

  return startingPoint;
}


/* Converts the list to an array of strings. The strings are copied
   into newly allocated character arrays.

   "Returns" both the new array as well as its length. The mechanism
   to return two results from a C function is the usual one: through
   pointers.

   If the list is empty (i.e. if the list pointer is NULL),
   sets *array to NULL and the length to 0.

   DIFFICULTY: 4
   POINTS POSSIBLE: 12

*/
void convert_to_array(char ***array, int *n, list_t *list) {
  list_t *crawler = list;
  char **strArray;
  char *strAlloc;
  int numberOfItems = length_list(list);
  int i = 0;

  if (list == NULL) {
    *array = NULL;
    *n = 0;
    return;
  }

  strArray = (char**) calloc(numberOfItems, sizeof(char));

  if (strArray == NULL) error_no_memory_left();

  while (crawler != NULL) {
    strAlloc = (char*) calloc(strlen(crawler->str)+1, sizeof(char));

    if (strArray == NULL) error_no_memory_left();

    strcpy(strAlloc, crawler->str);
    strArray[i] = strAlloc;

    crawler = crawler->next;
    i++;
  }

  *array = strArray;
  *n = numberOfItems;
}


/* Converts an array of length n to a list. The strings are
   copied into newly allocated memory locations.

   If the length is zero or negative returns NULL.

   DIFFICULTY: 2
   POINTS POSSIBLE: 6

*/
list_t *convert_from_array(char **array, int n) {
  list_t *startingPoint;
  list_t *current = NULL;
  list_t *prev = NULL;
  int i;
  int flag = 1;

  if (n == 0) {
    return NULL;
  }

  for (i = 0; i < n; i++) {
    current = (list_t*) malloc(sizeof(list_t));
    current->str = (char*) calloc(strlen(array[i])+1, sizeof(char));

    if (current == NULL || current->str == NULL) {
    error_no_memory_left();
  }

    strcpy(current->str, array[i]);

    if (flag) {
      startingPoint = current;
      flag = 0;
    }
    else prev->next = current;

    prev = current;
  }

  current->next = NULL;

  return startingPoint;
}


/* Compares two lists.

   If the lists are equal, returns a non-zero value (like 1).

   If the lists differ, returns zero.

   Two lists differ if they have different length or if at a certain
   index, they contain strings which are not equal. Two lists that
   do not differ are equal.

   This function may use the strcmp function. The strcmp function
   returns zero for two equal strings and returns a non-zero value
   otherwise.

   THIS FUNCTION MUST NOT ALLOCATE ANY MEMORY.

   THIS FUNCTION MUST RETURN ZERO AS SOON AS IT KNOWS THAT THE TWO
   LISTS CANNOT BE EQUAL.

   DIFFICULTY: 3
   POINTS POSSIBLE: 9

*/
int compare_lists(list_t *a, list_t *b) {
  list_t *crawlerA = a;
  list_t *crawlerB = b;

  if (length_list(a) != length_list(b)) {
    return 0;
  }

  while (crawlerA != NULL && crawlerB != NULL) {
    if (strcmp(crawlerA->str, crawlerB->str) != 0) {
      return 0;
    }
    crawlerA = crawlerA->next;
    crawlerB = crawlerB->next;
  }

  return 1;
}

/* Adds a string to an existing list. Adds the string *before* the
   k-th element of the existing list. The first element of the
   existing list has index zero.

   MODIFIES THE LIST ***IN PLACE***, DOES ***NOT*** COPY THE LIST.

   Returns the MODIFIED list.

   If the list is empty at the beginning, returns a list with
   one element, containing the given string.

   The string is copied into a newly allocated memory location.

   If k is negative, adds the element to the beginning of the list.

   If k is equal to or greater than the length of the list, adds the
   element to the end of the list.

   DIFFICULTY: 5
   POINTS POSSIBLE: 15

*/
list_t *add_before_kth_index(char *str, list_t *list, int k) {
  list_t *newItem;
  list_t *current = list;
  list_t *prev = NULL;
  int lengthList = length_list(list);
  int len = k;
  int i;

  if (len > lengthList) {
    len = lengthList;
  }

  newItem = (list_t*) malloc(sizeof(list_t));
  newItem->str = (char*) calloc(strlen(str)+1, sizeof(char));
  newItem->next = NULL;

  if (newItem == NULL || newItem->str == NULL) {
    error_no_memory_left();
  }

  strcpy(newItem->str, str);


  if (list == NULL) {
    return newItem;
  }

  if (len <= 0) {
    newItem->next = list;
    return newItem;
  }

  for (i = 0; i < len; i++) {
    prev = current;
    current = current->next;
  }

  prev->next = newItem;
  newItem->next = current;

  return list;
}

/* Deletes the k-th element of a list. The first element of the
   existing list has index zero.

   MODIFIES THE LIST ***IN PLACE***, DOES ***NOT*** COPY THE LIST.

   Returns the MODIFIED list.

   The string as well as the unlinked node in the linked list get
   freed.

   If k is not a valid index of the list, the function does nothing
   and just returns the unmodified list. An index is valid if it is
   between 0 (included) and the n (excluded), where n is the length of
   the list.

   CAUTION: The case k = 0, when the very first element is deleted
   from the list is different from the other cases k >= 1.

   DIFFICULTY: 6
   POINTS POSSIBLE: 18

*/
list_t *delete_at_kth_index(list_t *list, int k) {
  list_t *prev = NULL;
  list_t *curr = list;
  int i;

  if (k <= length_list(list)) {
    return list;
  }

  if (k == 0) {
    curr = list->next;
    free(list->str);
    free(list);
    return curr;
  }

  for (i = 0; i <= k; i++) {
    prev = curr;
    curr = curr->next;
  }

  prev->next = curr->next;

  free(curr->str);
  free(curr);

  return list;
}

/* Computes and returns the minimum string of the list.

   The minimum string is the string that orders first in alphabetical
   order.

   If the list is empty, returns NULL.

   Otherwise returns the pointer to the character array in the list
   that contains the minimum string.

   THE FUNCTION DOES NOT USE malloc, calloc NOR free. IT DOES NOT COPY
   THE STRING INTO A NEWLY ALLOCATED ARRAY. IT DOES NOT USE strcpy.

   The function may use strcmp.

   THE FUNCTION MUST NOT USE THE FUNCTION convert_to_array.
   THE FUNCTION MUST NOT USE THE FUNCTION sort_list.

   DIFFICULTY: 2
   POINTS POSSIBLE: 6

*/
char *compute_minimum(list_t *list) {
  list_t *crawler = list;
  char *min = list->str;

  if (list == NULL) {
    return NULL;
  }

  while (crawler->next != NULL) {
    if (strcmp(min, crawler->str) > 0) {
      min = crawler->str;
    }
    crawler = crawler->next;
  }

  return min;
}

/* Merges two arrays of character array pointers, a of length n and b
   of length m into one array res of lenght n + m.

   The arrays a and b are sorted by ascending alphabetical order.

   The result array is sorted as well.

   THE FUNCTION DOES NOT ALLOCATE ANY NEW MEMORY. THE STRINGS ARE NOT
   COPIED INTO NEWLY ALLOCATED ARRAYS. ONLY THE POINTERS TO THEIR
   FIRST CHARACTER ARE MOVED.

   THE FUNCTION MUST NOT USE strcpy.

   THE FUNCTION MAY USE strcmp.

   CAUTION: Read the specification and the code of the function
   sort_array_aux below before you start coding on this function.

   DIFFICULTY: 7
   POINTS POSSIBLE: 21

*/
void merge_arrays(char **res, char **a, int n, char **b, int m) {
  int aCount = 0;
  int bCount = 0;
  int resCount = 0;
  int loopFlag = 0;

  while (resCount < n+m) {

    if (aCount == n) {
      res[resCount] = b[bCount];
      resCount++;
      bCount++;
      loopFlag = 1;
    }
    else if (bCount == m) {
      res[resCount] = a[aCount];
      resCount++;
      aCount++;
      loopFlag = 1;
    }

    if (!loopFlag) {
      if (strcmp(a[aCount], b[bCount]) <= 0) {
        res[resCount] = a[aCount];
        resCount++;
        aCount++;
      }
      else {
        res[resCount] = b[bCount];
        resCount++;
        bCount++;
      }
    }
    loopFlag = 0;
  }
}

/* Auxillary function to sorts an array of characters by ascending
   alphabetical order.

   FOR THE OUTSIDE USER THE FUNCTION BEHAVES AS IF NO MEMORY
   ALLOCATION TOOK PLACE. THE FUNCTION HENCE FREES ALL MEMORY IT
   ALLOCATES. IT DOES NOT COPY THE STRINGS INTO NEWLY ALLOCATED
   ARRAYS. IT DOES NOT USE strcpy.

   The function is based on the merge-sort algorithm and
   is recursive.

   The function uses the helper function merge_arrays.

   Nothing needs to be changed here but the function is based on
   merge_arrays, which needs to be implemented above.

*/
void sort_array_aux(char **sorted_array, char **array, int n) {
  int n_left, n_right;
  char **array_left;
  char **array_right;
  char **temp_array_left;
  char **temp_array_right;

  if (n <= 0) return;
  if (n == 1) {
    sorted_array[0] = array[0];
    return;
  }

  n_left = n / 2;
  n_right = n - n_left;
  array_left = array;
  array_right = &array[n_left];

  temp_array_left = calloc(n_left, sizeof(char *));
  if (temp_array_left == NULL) {
    error_no_memory_left();
  }
  temp_array_right = calloc(n_right, sizeof(char *));
  if (temp_array_right == NULL) {
    error_no_memory_left();
  }

  sort_array_aux(temp_array_left, array_left, n_left);
  sort_array_aux(temp_array_right, array_right, n_right);

  merge_arrays(sorted_array, temp_array_left, n_left, temp_array_right, n_right);
  free(temp_array_left);
  free(temp_array_right);
}

/* Sorts an array of characters by ascending alphabetical order.

   THE FUNCTION MODIFIES THE ARRAY IN PLACE. FOR THE OUTSIDE USER THE
   FUNCTION BEHAVES AS IF NO MEMORY ALLOCATION TOOK PLACE. THE
   FUNCTION HENCE FREES ALL MEMORY IT ALLOCATES. IT DOES NOT COPY THE
   STRINGS INTO NEWLY ALLOCATED ARRAYS. IT DOES NOT USE strcpy.

   The function uses the auxilliary function sort_array_aux.

   Nothing needs to be changed here but the function is based on
   sort_array_aux implemented above.

*/
void sort_array(char **array, int n) {
  char **temp;
  int i;

  if (n <= 1) return;

  temp = calloc(n, sizeof(char *));
  if (temp == NULL) {
    error_no_memory_left();
  }

  sort_array_aux(temp, array, n);

  for (i=0;i<n;i++) {
    array[i] = temp[i];
  }
  free(temp);
}


/* Sorts a list, returning a copy of the sorted list.

   Nothing needs to be changed here.

*/
list_t *sort_list(list_t *list) {
  int i;
  int n = 0;
  char **array = NULL;
  list_t *res;

  if (list == NULL) return NULL;

  convert_to_array(&array, &n, list);
  sort_array(array, n);
  res = convert_from_array(array, n);


  for (i=0;i<n;i++) {
    free(array[i]);
  }

  free(array);

  return res;
}

/* The main function

   No changes are needed here.

*/
int main(int argc, char **argv) {
  const int STRING_BUFFER_LENGTH = 4096;
  char str[STRING_BUFFER_LENGTH];
  list_t *temp_list;
  list_t *list;
  list_t *copied_list;
  char **array;
  int n;
  int i;
  list_t *recreated_list;
  list_t *comparison_list;
  list_t *sorted_list;
  int k;
  char *min;

  temp_list = NULL;
  while (1) {
    printf("Please enter a string. Enter \"quit\" (without the quotes) to end the input.\n");
    input_string(str, STRING_BUFFER_LENGTH);
    if (strcmp(str, "quit") == 0)
      break;
    temp_list = add_to_list(str, temp_list);
  }
  list = revert_list(temp_list);
  delete_list(temp_list);

  printf("You have entered %d strings. The strings you entered are:\n", length_list(list));
  print_list(list);

  copied_list = copy_list(list);

  array = NULL;
  n = 0;
  convert_to_array(&array, &n, list);

  if (array != NULL) {
    printf("Here are again the %d strings you entered:\n", n);
    for (i=0; i<n; i++) {
      printf("%s\n", array[i]);
    }
  }

  recreated_list = NULL;
  if (array != NULL) {
    recreated_list = convert_from_array(array, n);
  }

  if (compare_lists(list, recreated_list)) {
    printf("The list could be successfully recovered.\n");
  } else {
    printf("The list could NOT be successfully recovered.\n");
  }

  printf("Please enter yet another string.\n");
  input_string(str, STRING_BUFFER_LENGTH);
  printf("Please enter an integer: ");
  scanf("%d", &k);

  list = add_before_kth_index(str, list, k);

  printf("I added the string \"%s\" before the %d-th element of the list. The list is now:\n", str, k);
  print_list(list);

  printf("The copied list still is:\n");
  print_list(copied_list);

  comparison_list = add_to_list("Snowflake", add_to_list("Snowflake", add_to_list("Little snowflake", NULL)));
  if (compare_lists(copied_list, comparison_list)) {
    printf("The copied list is equal to \"Snowflake\", \"Snowflake\", \"Little snowflake\".\n");
  } else {
    printf("The copied list is NOT equal to \"Snowflake\", \"Snowflake\", \"Little snowflake\".\n");
  }

  min = compute_minimum(copied_list);
  if (min == NULL) {
    printf("The copied list is empty.\n");
  } else {
    printf("The minimum string in the copied list is \"%s\".\n", min);
  }

  sorted_list = sort_list(copied_list);

  printf("The sorted list is:\n");
  print_list(sorted_list);

  printf("Please enter an integer: ");
  scanf("%d", &k);

  sorted_list = delete_at_kth_index(sorted_list, k);

  printf("The sorted list with the element of index %d removed is:\n", k);
  print_list(sorted_list);

  delete_list(list);
  delete_list(copied_list);
  if (array != NULL) {
    for (i=0; i<n; i++) {
      free(array[i]);
    }
    free(array);
  }
  delete_list(recreated_list);
  delete_list(comparison_list);
  delete_list(sorted_list);

  printf("\nREACHED END!!\n");

  return 0;
}
