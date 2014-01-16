/* by Tyler Davidson
 *
 * Graphical Editor NONTRIVIAL
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Table
{
public:
	Table(int n, int m) : height(n), width(m)
	{
		table = new string[height];
		for (int i = 0; i < height; ++i)
			table[i] = new string(width, '0');
	}

private:
	int height;
	int width;

	string * table;
};

int main()
{
	// Table table(5,6);
	return 0;
}