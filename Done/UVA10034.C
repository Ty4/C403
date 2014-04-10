/* by Tyler Davidson
 *
 * Freckles:		NONTRIVIAL		(Graph Theory)
 *
*/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define ii pair<int, int>
#define vi vector<int>

using namespace std;

struct Freckle
{
	double x;
	double y;
} freckles[205];

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
	int testCases;

	cin >> testCases;
	while (testCases--){
		int numOfFreckles;
		double mst_cost;
		double x, y;

		vector<pair<double, ii> > EdgeList;

		cin >> numOfFreckles;
		for (int i = 0; i < numOfFreckles; ++i){
			cin >> freckles[i].x >> freckles[i].y;
		}

		// Kruskal's
		for (int i = 0; i < numOfFreckles; ++i){
			for (int j = i + 1; j < numOfFreckles; ++j){
				double weight = sqrt(pow(freckles[j].x - freckles[i].x, 2.0) +
									 pow(freckles[j].y - freckles[i].y, 2.0));
				EdgeList.push_back(make_pair(weight, ii(i, j)));
			}
		}

		sort(EdgeList.begin(), EdgeList.end());

		mst_cost = 0;
		UnionFind UF(numOfFreckles);

		for (int i = 0; i < EdgeList.size(); ++i){
			pair<double, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}

		cout << fixed << setprecision(2) << mst_cost << endl;

		if (testCases) cout << endl;
	}

	return 0;
}
