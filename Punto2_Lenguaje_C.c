#include <stdio.h>
#include <stdlib.h>

typedef enum { S0, S1, S2, S3, S4, S5 } STATE_T;
typedef enum { ZERO, ONE } INPUT_T;

int Recognizer_001000(INPUT_T input) {
  static STATE_T state = S0;
  switch (state) {
    case S0: state = (input == ZERO) ? S1 : S0; break;
    case S1: state = (input == ZERO) ? S2 : S0; break;
    case S2: state = (input == ZERO) ? S2 : S3; break;
    case S3: state = (input == ZERO) ? S4 : S0; break;
    case S4: state = (input == ZERO) ? S5 : S0; break;
    case S5: state = (input == ZERO) ? S5 : S0; break;
  }
  return state == S5;
}

int main(void) {
  int input, counter = 0;
  for (int i = 0; i < 64; i++) {
    input = rand() % 2;
    printf("%d ", input);
    if (Recognizer_001000(input)) {
      printf("===> ACCEPT\n");
      counter++;
    } else {
      printf("REJECT\n");
    }
  }
  printf("Matches: %d\n", counter);
  return 0;
}
