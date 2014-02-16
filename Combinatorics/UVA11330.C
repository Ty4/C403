/* by Tyler Davidson
 *
 * Andy's Shoes: 		NONTRIVIAL		(Combinatorics)
 *
 */

#include <climits>
#include <cstdio>
#include <unordered_map>

using namespace std;

int cases, pairs;

int main()
{
	scanf("%d", &cases);

	while (cases-- > 0){
		scanf("%d", &pairs);
		unordered_map<int, int> mixedPairs;

		for (int i = 0; i < pairs; ++i){
			int leftShoe; int rightShoe;
			scanf("%d %d", &leftShoe, &rightShoe);
			mixedPairs.insert(pair<int,int>(leftShoe, rightShoe));
		}

		int min = INT_MAX;
		for (unordered_map<int,int>::iterator it = mixedPairs.begin(); it != mixedPairs.end(); ++it){
			int n = it->second;
			int len = 0;
			while (n != it->first){
				n = mixedPairs[n];
				len += 1;
			}
			if (len <= min)
				min = len;
		}

		printf("%d\n", min);;
	}

	return 0;
}
