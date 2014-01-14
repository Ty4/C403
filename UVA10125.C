#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;
	while (N != 0){
		vector<int> S;
		int A, B, C, D;

		// read in values for S
		for (int i = 0; i < N; ++i){
			int num;
			cin >> num;
			S.push_back(num);
		}

		for (size_t i = 0; i < S.size(); ++i){
			A = S[i];
			B = S[i]+1;

		}

		cin >> N;
	}

	return 0;
}