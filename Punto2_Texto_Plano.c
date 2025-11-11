/* Ruler 1         2         3         4         5         6         7        *//********************************************************************************
*   Drawn by:  Valeria Catalina Peña Calle
*
*   Diagram:  acceptor_001000
*
*   Purpose:  Finite Automaton that recognizes the 6-bit pattern "001000"
*
*******************************************************************************/
typedef enum { S0, S1, S2, S3, S4, S5, S6 } Q_T;
typedef enum { ZERO, ONE } SIGMA_T;

Q_T delta[7][2] = {
  /* ZERO,  ONE  */
  { S1,    S0 },   // S0
  { S2,    S0 },   // S1
  { S2,    S3 },   // S2
  { S1,    S4 },   // S3
  { S5,    S0 },   // S4
  { S5,    S0 },   // S5 (final can reenter)
  { S0,    S0 }    // S6 unused
};

Q_T q0 = S0;
Q_T F[] = { S5 };

