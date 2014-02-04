/* by Tyler Davidson
 *
 * Balancing Bank Accounts: 	NONTRIVIAL		(Arithmetic)
 *
*/

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class UnionFind
{
private:
	// debts maps the debtee to the pair of owee and amount
	map<string, pair<string,int> > debts;
	map<string, int> rank;
public:
	UnionFind(vector<string> & people)
	{
		for (vector<string>::iterator it = people.begin();
			 it != people.end(); ++it){
			debts[*it] = make_pair(*it, 0);
			rank[*it] = 0;
		}
	}

	string findDebtor(const string & debtee)
	{
		if(debts[debtee].first == debtee)
			return debtee;
		else
			return findDebtor(debts[debtee].first);
	}

	l
	void update(const string & debtee, const string & debtor, const int amount)
	{
		if (debts[debtor].first == debtor){
			debts[debtee].first = debtor;
			debts[debtee].second = amount;
		}
		else {
			debts[debtor].second -= amount;
			update(debtee, debts[debtor].first, amount);
		}
	}
};
int n, t;

int main()
{
	scanf("%d %d", &n, &t);
	while (n != 0 && t != 0){
		// read in the names
		vector<string> tmp;
		for (int i = 0; i < n; ++i){
			string name;
			cin >> name;
			tmp.push_back(name);
		}

		// read in the transactions
		// process transactions
		scanf("%d %d", &n, &t);
	} /* end while */
} /* end main */
