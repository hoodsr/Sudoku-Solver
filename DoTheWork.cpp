/****************************************************************
 * 'DoTheWork' class for Homework assignment 06. 
 * Class for solving a Sudoku solution by brute force recursively.
 *
 * Author/copyright:  Shannon Hood. All rights reserved.
 * Date: 04 November 2013
**/
#include "DoTheWork.h"
static const string TAG = "DoTheWork: ";

/****************************************************************
 * Constructor.
**/
DoTheWork::DoTheWork() {
}

/****************************************************************
 * Destructor.
**/
DoTheWork::~DoTheWork() {
}

/****************************************************************
 * Read the sudoku puzzle from an input file and then print the 
 * puzzle. Store "."s as empty entries using the dummy value. Then
 * call the recursive function to solve the puzzle and output 
 * the solution.
 *
 * @param inStream, outStream
**/
void DoTheWork::doTheWork(Scanner& inStream, ostream& outStream) {
	for(int row = ONE; row <= NINE; row++) {
		for(int col = ONE; col <= NINE; col++) {
			string nextString = inStream.next();
			int nextInt;
			if(nextString == ".")
				nextInt = DUMMY;
			else
				nextInt = Utils::stringToInteger(nextString);

			if(!board.isLegal()) {
				Utils::logStream << "Error in input. Illegal Sudoku board." << endl;
				exit(1);
			}

			board.setSquare(row, col, nextInt);
		}
	}
	
	board.display(outStream);
	addSquare(ONE, ONE, outStream);
	board.display(outStream);
}

/****************************************************************
 * Finds the first empty square and then substitutes a number.
 * Checks if the board is still legal, and if so, move on to the 
 * next square. If it is not legal, remove the last value and try 
 * the next value.
 *
 * @param row, col, outStream
 * @return true if board is still legal
**/
bool DoTheWork::addSquare(int row, int col, ostream& outStream) {
	while (board.getSquare(row, col) != DUMMY){
		col++;
		if(col > NINE) {
			col = ONE;
			row++;
		}
		if(row > NINE) // BASE CASE.
            return true;
	}

    for (int i = ONE; i <= NINE; i++){
		board.setSquare(row, col, i);		
		// board.display(cout);
		if (board.isLegal() && addSquare(row, col, outStream))
			return true;
	}

	board.unsetSquare(row, col);
    return false;
}
