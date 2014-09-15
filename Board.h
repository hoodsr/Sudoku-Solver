/****************************************************************
 * Header for the 'Board' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 9 May 2013
 * Used by Shannon Hood with permission.
**/

#ifndef BOARD_H
#define BOARD_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "Constants.h"

#include <algorithm>

class Board {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Board();
  virtual ~Board();

/****************************************************************
 * General functions.
**/
  bool isLegal();
  bool isLegal(int minRow, int maxRow, int minCol, int maxCol);
  void display(ostream& outStream);
  int getSquare(int row, int col);
  void setSquare(int row, int col, int value);
  void unsetSquare(int row, int col);

private:
/****************************************************************
 * Variables.
**/
  vector< vector<int> > theBoard;

/****************************************************************
 * Functions.
**/
};

#endif // BOARD_H
