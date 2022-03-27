// Standard headers
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  // TODO: unused parameters, remove these lines later
  UNUSED(attacker_position);
  UNUSED(defender_spy);

  // TODO: Implement Attacker logic here
  static int first_roll = 0;

  if (!first_roll) {
    srand(time(NULL));
    first_roll = 1;
  }

  int y_move = rand()%3 - 1; //Can go up, down, or not move on the y axis
  int x_move = rand()%3 - 1;
  x_move = (x_move == -1)? rand()%3 - 1 : x_move; // Giving a smaller chance of it going back
  
  printf("move == {%d, %d}\n", y_move, x_move);

  return (direction_t) {y_move, x_move};
}

/*----------------------------------------------------------------------------*/
