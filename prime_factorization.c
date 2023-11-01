#include <stdio.h>

int is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void print_prime_factors(int n) {
  int i = 2;
  while (n > 1) {
    if (is_prime(i) && n % i == 0) {
      printf("%d ", i);
      n /= i;
    } else {
      i++;
    }
  }
  printf("\n");
}

int main() {
  int n;

  printf("Enter a positive whole number: ");
  scanf("%d", &n);

  if (n <= 1) {
    printf("n must be greater than 1.\n");
    return 1;
  }

  printf("The prime factors of %d are: ", n);
  print_prime_factors(n);

  return 0;
}
