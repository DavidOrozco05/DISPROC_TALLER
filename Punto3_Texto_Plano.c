typedef enum { S0, S1, S2, S3, S4, S5, S6, S7, S8 } Q_T;
typedef enum {
 ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
 POINT, UPPER_E, LOWER_E, PLUS, MINUS, SPACE, NUL, OTHER
} SIGMA_T;

Q_T delta[9][18]; // se define en el código

Q_T q0 = S0;
Q_T F[] = { S3, S4, S7 }; // estados finales válidos
