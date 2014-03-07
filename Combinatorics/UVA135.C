#include <cstdio>
#include <iostream>

using namespace std;

int k;

int main()
{
	int n;
	while(scanf("%d", &k) == 1){
		n = k*k-k+1;

		cout << "k: " << k << " n: " << n << endl;
	}

	return 0;
}
