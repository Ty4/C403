/* by Tyler Davidson
 *
 * Let Me Count The Ways:       NONTRIVIAL      (Dynamic Programming)
 *
*/

#include<iostream>

using namespace std;

int m, coins[] = { 1, 5, 10, 25, 50 };
long ways[30010] = { 0 };

int main() {
    ways[0] = 1;
    for(int i = 0; i < 5; ++i)
        for(int j = coins[i]; j <= 30000; ++j)
            ways[j] += ways[j - coins[i]];

    while(cin >> m)
    	if (ways[m] == 1)
    		cout << "There is only 1 way to produce " << m << " cents change." << endl;
    	else
			cout << "There are " << ways[m] << " ways to produce "
				<< m << " cents change." << endl;
}
