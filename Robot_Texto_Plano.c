/* Ruler 1         2          3         4         5         6         7       */
/*******************************************************************************
*
* Drawn by: Juan Carlos Giraldo Carvajal
*
* e-mail: jcgiraldo@javeriana.edu.co
*
* Diagram: jcgiraldo_robot
*
* Purpose: Mealy Finite State Machine
*
* Source: Original design by the author
*
*******************************************************************************/
typedef enum { BEGINING, ADVANCING, ... , STATE_SIZE } STATE_T;
typedef enum { WALL, CORRIDOR } INPUT_T;
typedef enum { RIGHT, LEFT, FORWARD } OUTPUT_T;
STATE_T state_0 = BEGIN;

STATE_T transition[STATE_SIZE][2] = {
        { ADVANCING, BEGINING },
        { WALL, RIGHT },
        { CORRIDOR, LEFT },
};
OUTPUT_T output[STATE_SIZE][2] = {
{ RIGHT, LEFT },
{ RIGHT, RIGHT },
{ LEFT, FORWARD}
};