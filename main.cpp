
//-------------------------------------------------------------Header Files Used--------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "knight.h"

using namespace std;

//Recursive function which helps to solve the problem 
bool voyagingKnight(knight &g, int x, int y, int &step) {
	if (g.solved())
		return true;

	vector< vector<int> > moves = g.getmoves(x, y);

	for (int i = 0; i < moves.size(); i++) {
		g.setnum(moves[i][0], moves[i][1], step);
		step++;

		if (voyagingKnight(g, moves[i][0], moves[i][1], step))
			return true;

		g.setnum(moves[i][0], moves[i][1], 0);
		step--;
	}

	return false;
}

//---------------------------------------------------------------------The Main Function---------------------------------------------------------------------

int main() {
	int i, j;
	cout << "Enter rows and columns\n";
	cin >> i >> j;
	knight g1(i, j);
	g1.setnum(0, 0, 1);
	int step = 2;

	voyagingKnight(g1, 0, 0, step);

	g1.display(cout);

	cin.get();
	return 0;

//----------------------------------------------------------------------End of the Program-----------------------------------------------------------------------
}