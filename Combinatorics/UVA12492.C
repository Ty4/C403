/* by Tyler Davidson
 *
 * Rubik Cycle:		(Combinatorics)
 *
 */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char sequence[81];

typedef struct Face
{
	string tiles[3][3];

	Face(const string label)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				tiles[i][j].push_back(label.c_str());
				tiles[i][j].push_back(i*3+j);
			}
		}
	}
} Face;

typedef struct RubiksCube
{
	Face F, B, U, D, L, R;

	RubiksCube() : F("f"), B("b"), U("u"), D("d"), L("l"), R("r")
	{

	}
} RubiksCube;

int main()
{
	RubiksCube cube;
	while(scanf("%s", sequence) == 1){
		printf("%s\n", sequence);
	}
	return 0;
}
