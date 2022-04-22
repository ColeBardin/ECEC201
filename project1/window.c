#include "house.h"

/* Updates the graphics for the window @ coordinates (x, y) to match the
 * `state` array.
 *
 *   This function modifies the `house` array by updating the characters
 *   inside the window located at the zero indexed coordinates (x, y) to
 *   match the window's state in the `state` array.  If the window's
 *   state is 1, then the window is filled with the '#' character.
 *   Likewise, if the window's state is 0 in the `state` array, the
 *   window is filled with the ' ' character.
 *
 * Parameters:
 *   house -- pointer to characters representing the house
 *
 *   state -- pointer to the game state array
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_update_graphics (char *house, const int *state, int x, int y)
{
  /* Step 1: Write this function! */
	int x_i, y_i;
	
	/* Iterate for each window width character */	
	for (x_i = 0; x_i < WINDOW_WIDTH; x_i++){
		/* Iterate for each window height character */
		for (y_i = 0; y_i < WINDOW_HEIGHT; y_i++){
			/* If window state is ON (1) */
			if (state[x + 3*y] == 1) {
				/* Set the window index relevant characters to be '#' char */
				house[(11 + x*(WINDOW_WIDTH + 7) + x_i) + (8 + y_i + (WINDOW_HEIGHT+3)*y)*HOUSE_WIDTH] = '#';
			/* If winodw state is OFF (0) */
			}else{
				/* Set the window index relevant characters to be ' ' char */
				house[(11 + x*(WINDOW_WIDTH + 7) + x_i) + (8 + y_i + (WINDOW_HEIGHT+3)*y)*HOUSE_WIDTH] = ' ';
			}	
		/*
			house[(11 + x*(WINDOW_WIDTH + 7) + x_i) + (8 + y_i + (WINDOW_HEIGHT+3)*y)*HOUSE_WIDTH] = state[x+3*y]?'#':' ';
		*/
		}
	}
}


/* Toggles the state of the window @ coordinates (x, y) in the game
 * state array.
 *
 *   This function modifies the `state` array by toggling the value
 *   corresponding to the window at the provided coordinates (x, y).  If
 *   the current value is 1, then it will be toggled to 0.  Likewise, if
 *   the current value is 0, then it will be toggled to 1.
 *
 * Parameters:
 *   state -- pointer to the game state array
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_toggle_state (int *state, int x, int y)
{
  /* Step 2: Write this function! */
	/* If the window state is ON (1) */
	if (state[x + 3*y] == 1) {
		/* Set it to OFF (0) */
		state[x + 3*y] = 0;
	/* If the window state is OFF (0) */
	}else{
		/* Set it to ON (1) */
		state[x + 3*y] = 1;
	}
	/*
	state[x+3*y] = state[x+3*y]?0:1;
	*/
}


/* Toggles the state and, correspondingly, updates the graphics for the
 * window @ coordinates (x, y).
 *
 *   Given the zero indexed coordinates (x, y) of a window, this
 *   function ensures that the corresponding element in the game state
 *   array is toggled appropriately and that the graphics corresponding
 *   to that window are updated appropriately to reflect the new state.
 *
 *   Hint: call other functions you have written to make this easier.
 *
 * Parameters:
 *   state -- pointer to the game state array
 *
 *   house -- pointer to characters representing the house
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_update (int *state, char *house, int x, int y)
{
  /* Step 2: Write this function! */
	/* Toggle the window state at position (x,y) in the array */
	window_toggle_state (state, x, y);
	/* Update the graphics for window at state (x,y) on screen */
	window_update_graphics(house, state, x, y);
}


/* Toggles the lights based on the user's window selection.
 *
 *   Given the user's choice of window number, this function updates the
 *   corresponding window's (or windows') state and graphics, as
 *   necessary.
 *
 *   Hints:
 *     -- A primary job of this function will be to convert the choice
 *        of the user into the zero indexed (x, y) coordinates of a
 *        window.
 *
 *     -- Converting between `choice` and the (x, y) coordinates will
 *        probably be easier if you internally number the windows
 *        starting at zero (i.e. 0 thru 8 instead of 1 thru 9).
 *
 *     -- This function will need to call one other function
 *        (perhaps multiple times).
 *
 *   For Step 2, this function will only toggle the window
 *   corresponding to the user's selection.
 *
 *   For Step 3, this function will toggle the selected window
 *   and its neighbors (as described above in the instructions).
 *
 * Parameters:
 *    state -- pointer to the game state array
 *
 *    house -- pointer to characters representing the house
 *
 *   choice -- integer corresponding to the user's window selection
 *             (an integer value within the range 1 to 9)
 */
void window_toggle (int *state, char *house, int choice)
{
  /* Step 2: Write this function! (for single window toggle) */
	/* x coordinate of window if state array was 2D */
	int x = (choice-1)%3;
	/* y coordinate of window if state array was 2D */
	int y = (choice-1)/3;

	/* Update the window input by the user */
	window_update(state, house, x, y);  

  /* Step 3: Rewrite this function! (for multi-window toggle) */
	/* Switch statement on x coordinate of window */
	switch(x) {
		/* If it is a left edge window */
		case 0:
			/* Toggle the window to the right of it */
			window_update(state, house, x+1, y);  
			break;
		/* If it is a middle window x-wise */
		case 1:
			/* Toggle the windows to the right and left of it */
			window_update(state, house, x+1, y);  
			window_update(state, house, x-1, y);  
			break;
		/* If it is a right edge window */
		case 2:
			/* Toggle the window to the left of it */
			window_update(state, house, x-1, y);  
			break;
	}
	/* Switch statement on y coordinate of window */
	switch(y) {
		/* If it is a top edge window */
		case 0:
			/* Toggle the window below */
			window_update(state, house, x, y+1);  
			break;
		/* If it is a middle window y-wise */
		case 1:
			/* Toggle the windows above and below it */
			window_update(state, house, x, y+1);  
			window_update(state, house, x, y-1);  
			break;
		/* If it is a bottom edge window */
		case 2:
			/* Toggle the window above it */
			window_update(state, house, x, y-1);  
			break;
	}	
}
