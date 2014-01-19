/* by Tyler Davidson
 *
 * The Blocks Problem:	NONTRIVIAL	(Simulation)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a, b;
	int n;
	string command1, command2;
	vector<vector<int> > blocks;

	cin >> n;
	for (int i = 0; i < n; ++i) blocks.push_back(vector<int>);

	while(1){
		cin >> command1;
		if (command1.compare("quit") == 0) break;
		cin >> a >> command2 >> b;
	}

	return 0;
}
