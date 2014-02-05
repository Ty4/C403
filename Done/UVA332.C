/* by Tyler Davidson
 *
 * Rational Numbers from Repeating Fractions:	NONTRIVIAL 	(Arithmetic)
 *
 * This program reads in the numbers from stdin as strings, and treats the
 *   strings as though they're floating point numbers--"shuffling" the
 *   decimal point over as needed, instead of worrying about floating point
 *   arithmetic--and converting them to integers at the very end.
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int getJKPow(const int j, const int k, const string & X)
{
	string jkpow(X);
	for (int i = 0; i < k+j; ++i){
		char tmp = jkpow[i];
		jkpow[i] = jkpow[i+1];
		jkpow[i+1] = tmp;
	}
	jkpow.erase(k+j, jkpow.size()-1);
	return atoi(jkpow.c_str());
}

int getKPow(const int k, const string & X)
{
	string kpow(X);
	if (k > 0){
		for (int i = 0; i < k; ++i){
			char tmp = kpow[i];
			kpow[i] = kpow[i+1];
			kpow[i+1] = tmp;
		}
		kpow.erase(k, kpow.size()-1);
		return atoi(kpow.c_str());
	}
	else
		return 0;
}

int findNumer(const int j, const int k, const string & X)
{
	int jkpow = getJKPow(j, k, X);
	int kpow = getKPow(k, X);
	if (jkpow == 0)
		return 0;
	else if (j == 0)
		return kpow;
	else
		return jkpow - kpow;
}

int findDenom(const int j, const int k)
{
	if (j == 0)
		return pow(10,k);
	else
		return ((pow(10, k+j)) - pow(10, k));
}

int findGcd(const int num, const int den)
{
	return den == 0 ? num : findGcd(den, num % den);
}

int main()
{
	int caseNum = 1;
	int j,k;

	scanf("%d", &j);
	while (j != -1){
		int numer, denom, gcd;
		double x;
		string numstr;
		x = 0;

		int dig;
		while ((dig = getchar()) != '.');
		while (dig != '\n'){
			numstr.push_back(dig);
			dig = getchar();
		}
		k = numstr.size() - j - 1;
		x += atof(numstr.c_str());

		numer = findNumer(j,k,numstr); denom = findDenom(j,k);
		gcd = findGcd(numer, denom);

		if (numer == 0)
			printf("Case %d: 0/1\n", caseNum++);
		else
			printf("Case %d: %d/%d\n", caseNum++, numer/gcd, denom/gcd);
		scanf("%d", &j);
	}
	return 0;
}
