#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct sumMap
{
private:
	int A;
	int B;
	int sum;
public:
	sumMap(int _A, int _B, int _sum) : A(_A), B(_B), sum(_sum){}

	const int getSum() const { return sum; }

	const bool operator<(const sumMap & rhs) const
	{
		return sum < rhs.sum;
	}
};

int binSearch(const vector<int> & sums, const int & val, int first, int last)
{
	if (first > last) return -1;
	else {
		int mid = (first + last)/2;

		if (sums[mid] > val)
			return binSearch(sums, val, first, mid-1);
		else if (sums[mid] < val)
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
		set<sumMap> sumSet;
		set<sumMap>::iterator sumIt;
		vector<int> S, abSums;
		int A, B, C, D, sum;
		bool found = false;

		A = B = C = D = -1;

		// read in values for S
		for (int i = 0; i < N; ++i){
			int num;
			cin >> num;
			S.push_back(num);
		}

		cout << "Set: ";
		for (int i = 0; i < S.size(); ++i)
			cout << S[i] << " ";
		cout << endl;

		// create list of sums (A+B), store in sorted order
		for (size_t i = 0; i < S.size() - 1; ++i)
			for (size_t j = i+1; j < S.size(); ++j){
				sumMap tmp(S[i], S[j], S[i] + S[j]);
				sumSet.insert(tmp);
			}

		// put sums into vector, to ease binary search
		for (sumIt = sumSet.begin(); sumIt != sumSet.end(); ++sumIt)
			abSums.push_back((*sumIt).getSum());

		cout << "Sum Set: ";
		for (int i = 0; i < abSums.size(); ++i)
			cout << abSums[i] << " ";
		cout << endl;

		// search for D-C in abSums, starting with D at the largest value
		for (size_t i = S.size() - 1; i > 0; --i){
			for (int j = i-1; j >= 0; --j){
				sum = binSearch(abSums, S[i] - S[j], 0, abSums.size()-1);
				if (sum != -1){
					cout << "C: " << S[j] << ", D: " << S[i] << endl;
					if (S[i] > D){
						D = S[i]; C = S[j];
					}
				}
			}
		}

		if (D != -1) cout << D << endl;
		else cout << "no solution" << endl;

		cin >> N;
	}

	return 0;
}