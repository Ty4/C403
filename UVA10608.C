#include <iostream>
#include <vector>

using namespace std;

/*
 * disjoint set implementation from Avi's Programming Blog
 */
class disjoint_sets {
    struct disjoint_set {
        size_t parent;
        unsigned rank;
        disjoint_set(size_t i) : parent(i), rank(0) { }
    };
    vector<disjoint_set> forest;

public:
    disjoint_sets(size_t n)
    {
        forest.reserve(n);
        for (size_t i=0; i<n; i++)
            forest.push_back(disjoint_set(i));
    }

    size_t find(size_t i)
    {
        if (forest[i].parent == i)
            return i;
        else {
            forest[i].parent = find(forest[i].parent);
            return forest[i].parent;
        }
    }

    void merge(size_t i, size_t j)
    {
        size_t root_i = find(i);
        size_t root_j = find(j);
        if (root_i != root_j) {
            if (forest[root_i].rank < forest[root_j].rank)
                forest[root_i].parent = root_j;
            else if (forest[root_i].rank > forest[root_j].rank)
                forest[root_j].parent = root_i;
            else {
                forest[root_i].parent = root_j;
                forest[root_j].rank += 1;
            }
        }
    }

    int maxSetSize()
    {
    	int max = 0;
    	vector<disjoint_set>::iterator it = forest.begin();

    	for (; it != forest.end(); ++it){
    		cout << (*it).rank << endl;
    	}

    	return max;
    }
};

int main()
{
	int cases, citizens, pairs;
	int A, B;

	cin >> cases;
	for (int i = 0; i < cases; ++i){
		cin >> citizens >> pairs;

		disjoint_sets sets(citizens);
		for (int p = 0; p < pairs; ++p){
			cin >> A >> B;

			if (sets.find(A) != sets.find(B))
				sets.merge(A, B);
		}

		sets.maxSetSize();

	}
}