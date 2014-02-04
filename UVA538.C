/* by Tyler Davidson
 *
 * Balancing Bank Accounts: 	NONTRIVIAL		(Arithmetic)
 *
*/

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

#define psi pair<string,int>
#define msi map<string,int>
#define msp map<string,psi>

using namespace std;

class UnionFind
{
private:
	// debts maps the debtee to the pair of owee and amount
	msp debts;
	msi rank;
public:
	msp getDebts(){ return debts; }

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

	void update(const string & debtee, const string & debtor, const int amount)
	{
		if (debts[debtor].first == debtor){
			debts[debtee].first = debtor;
			debts[debtee].second = amount;
		}
		else if (debts[debtor].first == debtee){
			debts[debtor].second -= amount;
		}
		else {
			debts[debtor].second -= amount;
			if (debts[debtor].first == debts[debtee].first){
				debts[debtee].second += amount;
				update(debtee, debts[debtor].first, debts[debtee].second);
			}
			else
				update(debtee, debts[debtor].first, amount);
		}
	}
};
int n, t;

int main()
{
	int cases = 0;
	scanf("%d %d", &n, &t);
	while (n != 0 && t != 0){
		// read in the names
		vector<string> tmp;
		for (int i = 0; i < n; ++i){
			string name;
			cin >> name;
			tmp.push_back(name);
		}
		UnionFind debts(tmp);
		// read in the transactions
		for (int i = 0; i < t; ++i){
			string p1, p2;
			int amnt;
			cin >> p1 >> p2 >> amnt;
			debts.update(p2,p1,amnt);
		}
		printf("Case #%d\n", ++cases);
		msp debtMap = debts.getDebts();
		for (msp::iterator it = debtMap.begin(); it != debtMap.end(); ++it){
			if ((it->first) != (it->second).first){
				if ((it->second).second > 0)
					printf("%s %s %d\n", 
						(it->first).c_str(), 
						((it->second).first).c_str(),
						(it->second).second);
				else
					printf("%s %s %d\n", 
						((it->second).first).c_str(),
						(it->first).c_str(), 
						(it->second).second);
			}
		}
		printf("\n");
		scanf("%d %d", &n, &t);
	} /* end while */
} /* end main */
