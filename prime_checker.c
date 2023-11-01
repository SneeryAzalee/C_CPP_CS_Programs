#include <stdio.h>

int is_prime(int n) {
  int flag = 1;

  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      flag = 0;
      break;
    }
  }

  return flag;
}

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (is_prime(n)) {
    printf("%d is a prime number.\n", n);
  } else {
    printf("%d is not a prime number.\n", n);
  }

  return 0;
}
