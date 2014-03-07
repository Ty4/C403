#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int k;
int elements[14];

int nCk(const int n)
{
	int num = 1;
	for (int i = n; i > n - 6; --i)
    	num *= i;
    for (int i = 6; i > 1; --i)
    	num /= i;

    return num;
}

int main()
{
	cin >> k;
	while(k != 0){
		int choices = nCk(k);

		for (int i = 0; i < k; ++i)
			cin >> elements[i];


		for (int i = 0; i < k; ++i)
			cout << elements[i] << " ";
		cout << endl;

		for (int i = 0; i < choices; ++i){
			next_permutation(elements, elements+6);
			for (int i = 0; i < 6; ++i)
				cout << elements[i] << " ";
			cout << endl;
		}

		cin >> k;
	}

	return 0;
}
