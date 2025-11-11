#include <stdio.h>
#include <ctype.h>

typedef enum { S0, S1, S2, S3, S4, S5, S6, S7 } STATE_T;

int FloatRecognizer(char c) {
  if (c == 0) return 16; // NULL
  if (isspace(c)) return 15;
  if (c == '+') return 13;
  if (c == '-') return 14;
  if (c == '.') return 10;
  if (c == 'E') return 11;
  if (c == 'e') return 12;
  if (isdigit(c)) return c - '0';
  return 17;
}

int RecognizeFloat(const char *str) {
  STATE_T state = S0;
  for (int i = 0; ; i++) {
    int in = FloatRecognizer(str[i]);
    switch (state) {
      case S0:
        if (in == 15) state = S0;
        else if (in == 13 || in == 14) state = S1;
        else if (in <= 9) state = S2;
        else return 0;
        break;

      case S1:
        if (in <= 9) state = S2;
        else return 0;
        break;

      case S2:
        if (in <= 9) state = S2;
        else if (in == 10) state = S3;
        else if (in == 11 || in == 12) state = S5;
        else if (in == 16) return 1;
        else if (in == 15) return 1;
        else return 0;
        break;

      case S3:
        if (in <= 9) state = S4;
        else return 0;
        break;

      case S4:
        if (in <= 9) state = S4;
        else if (in == 11 || in == 12) state = S5;
        else if (in == 16 || in == 15) return 1;
        else return 0;
        break;

      case S5:
        if (in == 13 || in == 14) state = S6;
        else if (in <= 9) state = S7;
        else return 0;
        break;

      case S6:
        if (in <= 9) state = S7;
        else return 0;
        break;

      case S7:
        if (in <= 9) state = S7;
        else if (in == 16 || in == 15) return 1;
        else return 0;
        break;
    }
  }
}

int main(void) {
  char *tests[] = { "3.14", "-0.01e3", "12E-2", "1e", "3.4.5", NULL };
  for (int i = 0; tests[i]; i++) {
    printf("%-10s -> %s\n", tests[i],
           RecognizeFloat(tests[i]) ? "VALID" : "INVALID");
  }
  return 0;
}
