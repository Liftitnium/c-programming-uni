#include <stdio.h>
#include <stdlib.h>



void switchNumbers(int *a, int *b) { 
  int c = *a;
  *a = *b;
  *b = c;
};
int lengthOfString(const char *s) {
  int i, sum = 0;
  int size = sizeof(*s) / sizeof(s[0]);
  for (i = 0; i < size; i++) {
    sum += s[i];
  };
  return sum;
};
// couldn't do the concat function properly I don't want to use ai for error handling im gonna try to figure it out myself late
char *string_concat(const char *str1, const char *str2) {
  int len1 = lengthOfString(str1);
  int len2 = lengthOfString(str2);
  char *final = (char *)malloc(len1 + len2 + 1);
  for (int i = 0; i < len1; i++) {
    final[i] = str1[i];
  }
  for (int j = 0; j < len2; j++) {
    final[len1 + j] = str2[j];
  }
  final[len1 + len2] = '\0';
  return final;
};

int main(int argc, char const *argv[])
{
  int x = 5;
  int y = 7;
  printf("x is %d and y is %d before swapping/n", x, y);
  switchNumbers(&x, &y);
  printf("x is %d and y is %d after swapping/n", x, y);
  char str1[] = "best";
  char str2[] = "professor";
  char *final = string_concat(str1, str2);
  printf("Concatenated string: %s\n", final);
  return 0;
}
