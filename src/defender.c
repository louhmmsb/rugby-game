// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  // TODO: unused parameters, remove these lines later
  UNUSED(attacker_spy);

  // TODO: Implement Defender logic here
  static position_t defender_old_position = INVALID_POSITION;
  static unsigned char first_turn = 0;
  static int direction_y = 1;
  direction_t next_direction = (direction_t) DIR_LEFT;

  if (!first_turn) {
    first_turn = 1;
  }

  else if (equal_positions(defender_position, defender_old_position)){
    direction_y *= -1;
    next_direction = (direction_t) {direction_y, 0};
  }

  else {
    next_direction = (direction_t) {direction_y, 0};
  }
  
  printf("defender_move == {%d, 0}\n", direction_y);
  defender_old_position = defender_position;
  return next_direction;

}

/*----------------------------------------------------------------------------*/
