/* by Tyler Davidson
 *
 * Minesweeper
 *
 * This program outputs a simple version of the Minesweeper completion screen.
 * Given a grid for input, showing where the mines are, this program looks
 *   through the entire grid, and upon finding a mine, increments the value of
 *   each of its neighbours that aren't mines, showing that they are close to
 *   a mine.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

// input: the minefield, the bounds, and the location of the current square
void incrNeighbours(int ** & field, int n, int m, int i, int j)
{
	for(int k = i-1; k <= i+1; ++k){
		for (int l = j-1; l <= j+1; ++l){
			// bound checks, accounting for the edges of the grid
			if ((k < 0) || (l < 0)) continue;
			if ((k >= n) || (l >= m)) continue;
			if (field[k][l] != '*')
				++(field[k][l]);
		}
	}
}

int main()
{
	int n, m;
	int fieldNum = 0;
	// read in n and m
	cin >> n >> m;

	while (n != 0 && m != 0){
		++fieldNum;
		if (fieldNum > 1) cout << endl;
		int ** inputField = new int*[n];
		for (int i = 0; i < n; ++i)
			inputField[i] = new int[m];

		int ** mineField = new int*[n];
		for (int i = 0; i < n; ++i)
			mineField[i] = new int[m];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				mineField[i][j] = 0;


		// fill 2D array with input
		string field;
		for (int i = 0; i < n; ++i){
			cin >> field;
			string::iterator it = field.begin(), end = field.end();
			for(int j = 0; j < m; ++j){
				inputField[i][j] = *it;
				if (inputField[i][j] == '*') mineField[i][j] = '*';
				++it;
			}
		}


		// fill duplicate array with appropriate values
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (mineField[i][j] == '*')
					incrNeighbours(mineField, n, m, i, j);
			}
		}

		// for printing purposes only!
		cout << "Field #" << fieldNum << ":" << endl;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (mineField[i][j] == '*') cout << "*";
				else cout << mineField[i][j];
			}
			cout << endl;
		}

		// clear space for new field
		for (int i = 0; i < n; ++i)
			delete [] mineField[i];
		delete [] mineField;
		for (int i = 0; i < n; ++i)
			delete [] inputField[i];
		delete [] inputField;

		cin >> n >> m;
	}

	return 0;
}