/* Ruler 1         2         3         4         5         6         7        */

/* robot_maze.c ****************************************************************/
/*                                                                            */
/*   +----+ +----+              FINITE AUTOMATON / FINITE STATE MACHINE       */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **      Implementation of a simple robot maze solver        */
/*    |  |   | *  *       using a Finite State Machine in ANSI C.             */
/*    |  |   | *  *                                                           */
/*    |******| *  *                                                           */
/*    |**  **| *  *                                                           */
/*    ++*  ** **  *       DEVELOPED BY: Valeria Catalina Peña Calle           */
/*     +**  ***  **                      Pontificia Universidad Javeriana     */
/*      +**     **                                                            */
/*        *******         Bogota, D.C., November 11th, 2025.                  */
/*                                                                            */
/*          Copyright (C) Department de Electronics                           */
/*                        School of Engineering                               */
/*                        Pontificia Universidad Javeriana                    */
/*                        Bogota - Colombia - South America                   */
/*                                                                            */
/***************************** YOU MAY ADAPT THIS FRAME FOR YOUR OWN PURPOSES */

/********************************** Headers ***********************************/

#include <stdio.h>
#include <stdlib.h>

/************************** Declarations of New Types *************************/

typedef enum { S0, S1 } STATE_T;
typedef enum { WALL, CORRIDOR } SENSOR_T;
typedef enum { RIGHT, LEFT, FORWARD } ACTION_T;

/*********************** Definition of Public Functions ***********************/

/*FN****************************************************************************
*
*   int Robot_Maze( SENSOR_T input, ACTION_T *output );
*
*   Purpose: Control robot navigation through a maze using sensor readings
*
*   Origin:  Derived from a Mealy Machine example
*
*   Plan:    Finite State Machine for wall-following behavior
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE   COMMENT
*   -----------------------------------------------------------------------
*   Nov 11/2025  Student        Initial implementation and documentation
*
*******************************************************************************/

int Robot_Maze( SENSOR_T input, ACTION_T *output )
{
static STATE_T state = S0;

switch( state )
{
	case S0:
		if( input == WALL ) {
			*output = RIGHT;
			state = S0;
		} 
		else if( input == CORRIDOR ) {
			*output = LEFT;
			state = S1;
		}
	break;

	case S1:
		*output = FORWARD;
		state = S0;
	break;

} /* switch */

return 1;

} /* Robot_Maze */


/******************************* Main Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Simulate robot behavior based on random sensor inputs
*
*   Origin:  Educational FSM implementation
*
*   Plan:    Generate random readings and show robot actions
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Nov 11/2025  Student       Initial implementation and documentation
*
*******************************************************************************/

int main()
{
SENSOR_T input;
ACTION_T action;

for( int i = 0; i < 10; i++ ) {
	input = rand() % 2;  /* 0 = WALL, 1 = CORRIDOR */
	Robot_Maze( input, &action );

	printf("Sensor: %s -> Action: %s\n",
		(input == WALL) ? "WALL" : "CORRIDOR",
		(action == RIGHT) ? "RIGHT" :
		(action == LEFT) ? "LEFT" : "FORWARD");
}

return 0;

} /* main */
