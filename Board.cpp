/****************************************************************
 * Class for doing the board.
 *
 * Author/copyright:  Shannon Hood and Duncan Buell. All rights 
 * reserved.
 * Date: 04 November 2013
**/
#include "Board.h"
static const string TAG = "Board: ";

/****************************************************************
 * Constructor.
 * Initialize a nine by nine board with dummy values. The dummy 
 * represents an empty square.
**/
Board::Board() {
	vector<int> column;
	for(int col = 0; col <= NINE; col++)
		column.push_back(DUMMY);

	for(int row = 0; row <= NINE; row++)
		this->theBoard.push_back(column);
}

/****************************************************************
 * Destructor.
**/
Board::~Board() {
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * Get a value stored in the board by its row and column.
 * Returns the dummy value for an empty square.
 *
 * @param row, col
 * @return value stored
**/
int Board::getSquare(int row, int col) {
	if(row <= NINE && col <= NINE) 
		return this->theBoard[row][col];
	else {
		return DUMMY;
		Utils::logStream << "ERROR: Square out of bounds." << endl;
	}
}

/****************************************************************
 * Sets the value stored in the board by its row and column..
 *
 * @param row, col, value to be set
**/
void Board::setSquare(int row, int col, int value) {
	if(row <= NINE && col <= NINE) 
		this->theBoard[row][col] =  value;
	else 
		Utils::logStream << "ERROR: Square out of bounds." << endl;
}

/****************************************************************
 * Unset a square given its row and column location in the board.
 * This is done by setting it equal to the dummy value.
 *
 * @param row, col
**/
void Board::unsetSquare(int row, int col) {
	if(row <= NINE && col <= NINE) 
		this->theBoard[row][col] = DUMMY;
	else
		Utils::logStream << "ERROR: Square out of bounds." << endl;
}

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to check if the entire board is legal.
 * Checks every row, column, and square to ensure every value is
 * between the predefined constants of one and nine, and that 
 * there are no duplicate values in each tested area.
 *
 * @return true if legal, false if not
**/
bool Board::isLegal() {
	for(int row = ONE; row <= NINE; ++row) {
		if(!isLegal(row, row, ONE, NINE))
			return false;
	}

	for(int col = ONE; col <= NINE; ++col) {
		if(!isLegal(ONE, NINE, col, col))
			return false;
	}

	for(int row = ONE; row <= NINE; row = row+3) {
		for(int col = ONE; col <= NINE; col = col+3) {
			if(!isLegal(row, row+2, col, col+2))
				return false;
		}
	}
	return true;
}

/****************************************************************
 * Function to check if a row, column, or square is legal.
 * A row, column, or square is legal if the values lie between one
 * and zero and there are no duplicate values.
 * Note: To test a column, set the min and max column to the 
 * column number, the min row to one, and the max row to nine. 
 * Switch this to test one column. For squares, use groups of 
 * three starting from one.
 *
 * @return true if legal, false if not
**/
bool Board::isLegal(int minRow, int maxRow, int minCol, int maxCol) {
	vector<int> currentValues;

	for(int row = minRow; row <= maxRow; ++row) {
		for(int col = minCol; col <= maxCol; ++col) {
			if(this->theBoard[row][col] != DUMMY && (this->theBoard[row][col] < ONE || this->theBoard[row][col] > NINE))
				return false;
			if(this->theBoard[row][col] != DUMMY) 
				currentValues.push_back(this->theBoard[row][col]);
		}
	}

	sort(currentValues.begin(), currentValues.end());
	return (currentValues.end() == unique(currentValues.begin(), currentValues.end()));
}

/****************************************************************
 * Function for displaying the board.
**/
void Board::display(ostream& outStream) {
	outStream << "**************************************************" << endl;
	for(int row = ONE; row <= NINE; ++row) {
		for(int col = ONE; col <= NINE; ++col) {
			vector<int> theRow = this->theBoard[row];
			if(DUMMY == theRow[col]) {
				outStream << " . ";
				outStream.flush();
			}
			else {
				outStream << " " << theRow[col] << " ";
				outStream.flush();
			}
			if((0 == col%THREE) && (col < NINE)) {
				outStream << "|";
				outStream.flush();
			}
		} // for(int col = ONE; col <= NINE; ++col)

		outStream << endl;
		outStream.flush();
		if((0 == row%THREE) && (row < NINE)) {
		  outStream << "---------|---------|---------" << endl;
		  outStream.flush();
		}
	} // for(int row = ONE; row <= NINE; ++row)
	outStream << "**************************************************" << endl;
}

