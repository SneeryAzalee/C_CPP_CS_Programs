#include <stdio.h>
#include <conio.h>

int main() {
  while (1) {
    printf("This line will print repeatedly until you press enter.\n");

    if (kbhit()) {
      if (getch() == '\n') {
        break;
      }
    }
    
    usleep(10 * 1000);
  }

  return 0;
}
