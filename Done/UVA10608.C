/* by Tyler Davidson
 *
 * Friends
 *
 * This program utilizes the union-find algorithm for it's solution.
 * Once the sets are all made and divided up, I created a function that
 *    uses an integer array to count the size of each set. Each index
 *    represents a (possible) root node, and the value at that index is the
 *    size of the tree for which it is the root.
 */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class disjoint_sets {
    struct person {
        size_t parent;
        int rank;
        person(size_t i) : parent(i), rank(0) { }
    };
    vector<person> friendGroups;
    vector<person>::iterator fgIt;

public:
	// takes the place of function MakeSet
    disjoint_sets(size_t n)
    {
        friendGroups.reserve(n);
        for (size_t i=0; i<=n; i++)
            friendGroups.push_back(person(i));
    }

    // follows parent nodes until it finds the root of the set
    //    returns the index of the root
    int find(size_t x)
    {
    	if (friendGroups[x].parent != x)
    		friendGroups[x].parent = find(friendGroups[x].parent);
    	return friendGroups[x].parent;
    }

    //
    void mergeSets(const int & x, const int & y)
    {
    	int xRoot = find(x);
    	int yRoot = find(y);
    	if (xRoot == yRoot) return;

    	if (friendGroups[xRoot].rank < friendGroups[yRoot].rank)
    		friendGroups[xRoot].parent = yRoot;
    	else if (friendGroups[xRoot].rank > friendGroups[yRoot].rank)
    		friendGroups[yRoot].parent = xRoot;
    	else{
    		friendGroups[yRoot].parent = xRoot;
    		friendGroups[xRoot].rank += 1;
    	}
    }

    int maxSetSize()
    {
    	int sizes[friendGroups.size()];
    	int max = 0;

    	for (size_t i = 0; i < friendGroups.size(); ++i)
    		sizes[i] = 0;

    	fgIt = friendGroups.begin();
    	for (; fgIt != friendGroups.end(); ++fgIt)
    		sizes[find((*fgIt).parent)] += 1;

    	for (size_t i = 0; i < friendGroups.size(); ++i)
    		if (sizes[i] > max) max = sizes[i];

    	return max;
    }
};

int main()
{
	int cases, citizens, pairs;
	int A, B;
	int max = 0;

	scanf("%d", &cases);
	for (int i = 0; i < cases; ++i){
		scanf("%d %d", &citizens, &pairs);

		disjoint_sets sets(citizens);
		for (int p = 0; p < pairs; ++p){
			scanf("%d %d", &A, &B);

			if (sets.find(A) != sets.find(B))
				sets.mergeSets(A, B);
		}
		max = sets.maxSetSize();
		cout << max << endl;
	}
}