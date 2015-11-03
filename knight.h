
// Header File : knight.h

#ifndef _KNIGHT_H_ // If not define
#define _KNIGHT_H_ // Define it

//-------------------------------------------------------------Header Files Used--------------------------------------------------------------------------

#include<vector>
#include<iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------

// Class Knight
class knight
{
private:

	//Private Attribute
	vector<vector<int>>knight_;
public:

	//Public Member Function

	// Alternate Constructor
	knight(int rows, int colms);

	// Boolean function to check whether or not the grid is complete
	bool solved();

	// This function checks the posible move/moves from a particular position on the board
	vector < vector<int>> getmoves(int i, int j);

	// Boolean function returns true after assigning the value to a particular position on the board.
	bool setnum(int row, int col, int value);

	// Operator Overload
	vector<int>& operator[] (int num);

	// Void function to display the grid
	void display(ostream & out);

	//-----------------------------------------------------------End of Program-------------------------------------------------------------------

};
#endif