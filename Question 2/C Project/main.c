#include <stdio.h>

char rowIds[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int seating[10][15] = {0};


int main() {
  int tickets = 0;
  printf("Enter number of tickets: ");
  scanf(" %d", &tickets);

  if (tickets > 15) {
    return -1;
  }

  for (int row = 0; row < 10; row++) {
    int free_seats = 0;
    int shouldBreak = 0;

    for (int seat = 0; seat < 15; seat++) {
      if (seating[row][seat] == 0) {
        free_seats++;
      } else {
        free_seats = 0;
      }

      if (free_seats == tickets) {
        shouldBreak = 1;
        printf("\nBest seats:\n");

        for (int i = free_seats - 1; i >= 0; i--) {
          printf("%c%d\n", rowIds[row], seat - i + 1);
          seating[row][seat - i] = 1;
        }

        break;
      }
    }

    if (shouldBreak == 1) {
      break;
    }
  }

  return 0;
}
