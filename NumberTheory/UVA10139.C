#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

map<int,int> lhsFreq;
map<int,int> rhsFreq;

void primeFact(const int x)
{
	int i;
	int c;

	c = x;
	i = 2;
	while((c%2) == 0){
		primeFreq[i] += 1;
		c /= 2;
	}

	i = 3;
	while (i <= (sqrt(c)+1)){
		if ((c%i) == 0){
			primeFreq[i] += 1;
			c /= i;
		}
		else
			i += 2;
	}

	if (c > 1)
		primeFreq[c] += 1;
}

void factorFactorial(const int n)
{
	for (int i = n; i > 0; ++i){

	}
}

int main()
{
	return 0;
}
