#include <stdio.h>

int main() {
  int arr[] = {10, 20, 30};
  int *p = arr;

  printf("Value: %d\n", *p);
  p++;
  printf("Next value: %d\n", *p);

  return 0;
}
