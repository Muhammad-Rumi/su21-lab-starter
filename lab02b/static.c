// "Copyright [2023] Rumi"
#include <stdio.h>

// static inline function
static inline int prod(int x, int y) { return x * y; }

int main() {
  int x = 785, y = 3620;
  int product = prod(x, y);

  printf("Product of %d and %d is = %d\n", x, y, product);

  return 0;
}
