#include <stdio.h>

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  int g = gcd(a, b);
  printf("The greatest common factor of %d and %d is %d.\n", a, b, g);

  return 0;
}
