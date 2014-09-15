/****************************************************************
 * Header for the 'DoTheWork' class.
 *
 * Author/copyright: Duncan Buell
 * Used by Shannon Hood with permission.
 * Date: 9 May 2013
**/

#ifndef DOTHEWORK_H
#define DOTHEWORK_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "Constants.h"

#include "Board.h"

class DoTheWork {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  DoTheWork();
  virtual ~DoTheWork();

/****************************************************************
 * General functions.
**/
  void doTheWork(Scanner& inStream, ostream& outStream);

private:
/****************************************************************
 * Variables.
**/
  int depth;
  Board board;

/****************************************************************
 * Functions.
**/
  // bool addSquare(int& depth, ostream& outStream);
  bool addSquare(int r, int c, ostream& outStream);

};

#endif // DOTHEWORK_H
