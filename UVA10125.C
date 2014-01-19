/* by Tyler Davidson
 *
 * SumSets:	NONTRIVIAL	(Data Structures)
 */

#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// makeshift map, with the combination of first and second acting as the key
// first < second
struct sumMap
{
	sumMap(int _first, int _sec, int _sum) : sum(_sum)
	{
		if (_first <= _sec){
			first = _first;
			second = _sec;
		}
		else{
			first = _sec;
			second = _first;
		}

	}

	const int getSum() const { return sum; }
	const int getSecond() const { return second; }

	const bool isUnique(const sumMap & rhs) const
	{
		if (first == rhs.first) return false;
		if (first == rhs.second) return false;
		if (second == rhs.first) return false;

		return second != rhs.second;
	}

	bool operator<(const sumMap & rhs) const
	{
		if (sum <= rhs.sum) return true;
		return false;
	}

	void print() const
	{
		cout << "First: " << first << ", Second: " << second;
		cout << ", Sum: " << sum << endl;
	}


private:
	int first;
	int second;
	int sum;

};

// returns the index of sums that matches val
int binSearch(const vector<sumMap> & sums, const sumMap & val,
	int first, int last)
{
	if (first > last) return -1;
	else {
		int mid = (first + last)/2;

		if (sums[mid].getSum() > val.getSum())
			return binSearch(sums, val, first, mid-1);
		else if (sums[mid].getSum() < val.getSum())
			return binSearch(sums, val, mid+1, last);
		else
			return mid;
	}
}

int main()
{
	int N;

	cin >> N;
	while (N != 0){
		int max = -1;
		set<sumMap> sumSet;
		set<sumMap>::iterator sumIt;
		set<sumMap> diffSet;
		set<sumMap>::iterator diffIt;
		vector<int> S;
		vector<sumMap> abSums, cdDiffs;

		for (int i = 0; i < N; ++i){
			int num;
			cin >> num;
			S.push_back(num);
		}

		// create list of sums (A+B), store in sorted order
		for (size_t i = 0; i < S.size() - 1; ++i){
			for (size_t j = i+1; j < S.size(); ++j){
				sumMap tmp(S[i], S[j], S[i] + S[j]);
				sumSet.insert(tmp);
			}
		}

		// create list of diffs (D-C), store in sorted order
		for (size_t i = S.size()-1; i > 0; --i){
			for (int j = i-1; j >=0 ; --j){
				sumMap tmp(S[i], S[j], S[i] - S[j]);
				diffSet.insert(tmp);
			}
		}

		for (sumIt = sumSet.begin(); sumIt != sumSet.end(); ++sumIt)
			abSums.push_back(*sumIt);

		for (diffIt = diffSet.begin(); diffIt != diffSet.end(); ++diffIt)
			cdDiffs.push_back(*diffIt);

		vector<sumMap>::reverse_iterator rDiffIt = cdDiffs.rbegin();
		for (; rDiffIt != cdDiffs.rend(); ++rDiffIt){
			int match = binSearch(abSums, (*rDiffIt), 0, abSums.size()-1);
			if (match > -1){
				if (abSums[match].isUnique(*rDiffIt))
					if ((*rDiffIt).getSecond() > max)
						max = (*rDiffIt).getSecond();
			}
		}

		if (max > -1) cout << max << endl;
		else cout << "no solution" << endl;

		cin >> N;
	}

	return 0;
}