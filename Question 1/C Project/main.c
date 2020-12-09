#include <stdio.h>

int main() {
  int rings = 0;
  printf("Enter number of rings: ");
  scanf(" %d", &rings);
  printf("\n");

  // question asked for 1-indexed array :/
  int teeth_per_ring[9] = {0};

  for (int i = 1; i <= rings; i++) {
    int shouldRepeat = 1;

    while (shouldRepeat == 1) {
      shouldRepeat = 0;
      int last_teeth = -1;

      if (i != 1) {
        last_teeth = teeth_per_ring[i - 1];
      }

      printf("\nHow many teeth in ring %d: ", i);
      scanf("%d", &teeth_per_ring[i]);

      if (last_teeth != -1 && teeth_per_ring[i] >= last_teeth) {
        shouldRepeat = 1;
        printf("\nThis ring must have fewer teeth than the previous ring!");
      }
    }
  }

  return 0;
}
