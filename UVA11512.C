git /* by Tyler Davidson
 *
 * GATTACA: (Strings)
 *
 * Input
 *
 * The first line of the input contains an integer T specifying the number of
 * test cases ( 1 <= T $ <= 100 ). Each test case consists of a single
 * line of text that represents a DNA sequence S of length n
 * ( 1 <= n <= 1000 ).
 * You can suppose that each sequence S only contains the letters
 * A, C, G and T.
 *
 * Output
 *
 * For each sequence in the input, print a single line specifying the largest
 * substring of S that appears two or more times repeated in S , followed by a
 * space, and the number of ocurrences of the substring in S .
 * If there are two or more substrings of maximal length that are repeated,
 * you must choose the least according to the lexicographic order.
 * If there is no repetition in S , print ``No repetitions found!''
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAXN 	65536
#define MAXLG 	17


struct entry
{
    int nr[2];
    int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N,i;
int step, doneTill;

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int main()
{
	int testCases;
	char A[MAXN];

    gets(A);
    testCases = atoi(A);
    for (int i = 0; i < testCases; ++i){
	    gets(A);
	    cout << A << endl;
	    for(N=strlen(A), i = 0; i < N; ++i)
	        P[0][i] = A[i] - 'a';

	    for(step=1, doneTill = 1; doneTill < N; ++step, doneTill *= 2)
	    {
	        for(i=0; i < N; ++i)
	        {
	            L[i].nr[0]=P[step- 1][i];
	            L[i].nr[1]=i +doneTill <N? P[step -1][i+ doneTill]:-1;
	            L[i].p= i;
	        }
	        sort(L, L+N, cmp);
	        for(i=0; i < N; ++i)
	            P[step][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[step][L[i-1].p] : i;
	    }
	}
    return 0;
}