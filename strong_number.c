#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int is_strong_number(int n) {
  int sum = 0;
  int digit;
  while (n > 0) {
    digit = n % 10;
    sum += factorial(digit);
    n /= 10;
  }

  return sum == n;
}

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (is_strong_number(n)) {
    printf("%d is a strong number.\n", n);
  } else {
    printf("%d is not a strong number.\n", n);
  }

  return 0;
}
