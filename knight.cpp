
// Class Implementation: knight.cpp

//-------------------------------------------------------------Header Files Used--------------------------------------------------------------------------

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"knight.h"
#include<iomanip>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------

// Alternate Constructor 
knight::knight(int rows, int colms){
	knight_.assign(rows, vector<int>(colms, 0));
}

// Operator Overload
vector<int>& knight::operator[] (int num) {
	return knight_[num];
}

// Boolean function to check whether or not the grid is complete
bool knight::solved() {
	for (int i = 0; i < knight_.size(); i++)
		for (int j = 0; j < knight_[i].size(); j++)
			if (knight_[i][j] == 0)
				return false;
	return true;
}

// Inspector

// This function checks the posible move/moves from a particular position on the board
vector < vector<int> > knight::getmoves(int x, int y) {
	vector<vector<int>> moves;
	vector<int> temp;
	
	temp.push_back(x - 2);
	temp.push_back(y - 1);
	moves.push_back(temp);
	temp.clear();

	temp.push_back(x - 2);
	temp.push_back(y + 1);
	moves.push_back(temp);
	temp.clear();

	temp.push_back(x - 1);
	temp.push_back(y - 2);
	moves.push_back(temp);
	temp.clear();

	temp.push_back(x - 1);
	temp.push_back(y + 2);
	moves.push_back(temp);
	temp.clear();

	temp.push_back(x + 2);
	temp.push_back(y - 1);
	moves.push_back(temp);
	temp.clear();

	temp.push_back(x + 2);
	temp.push_back(y + 1);
	moves.push_back(temp);
	temp.clear();
	
	temp.push_back(x + 1);
	temp.push_back(y - 2);
	moves.push_back(temp);
	temp.clear();
	
	temp.push_back(x + 1);
	temp.push_back(y + 2);
	moves.push_back(temp);
	temp.clear();

	// This part of the code checks whether or not the move is illegal or the position is occupied
	for (int i = 0; i < moves.size(); i++) {
		if (moves[i][0] < 0 || moves[i][0] >= knight_.size() || moves[i][1] < 0 || moves[i][1] >= knight_[0].size() || knight_[moves[i][0]][moves[i][1]] != 0) {
			moves.erase(moves.begin() + i);
			i--;
		}
	}

	return moves;
}

// Boolean function returns true after assigning the value to a particular position on the board
bool knight:: setnum(int row, int col, int value)
{
	knight_[row][col] = value;
	return true;
}

// Void function to display the grid
void knight::display(ostream & out)
{
	out << endl << endl;
	
	for (int i = 0; i < knight_.size(); i++)
	{ 
		out << setw(2) << "#|";
		for (int j = 0; j < knight_[i].size(); j++)
		{
			//out << "#";
			out << setw(3)<<knight_[i][j] <<" ";
			out << "|";
			out << "#";
		}
		out << endl;
	}
	
}





