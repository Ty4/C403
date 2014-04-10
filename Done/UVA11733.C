#include <vector>

#define vi vector<int>

using namespace std;

class UnionFind
{
private: vi parent, rank;
public:

	UnionFind(int N)
	{
		rank.assign(N, 0);
		parent.assign(N, 0);
		for (int i = 0; i < N; ++i)
			parent[i] = i;
	}

	int findSet(int i){
		return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
	}

	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) parent[y] = x;
			else {
				parent[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main()
{
	return 0;
}
