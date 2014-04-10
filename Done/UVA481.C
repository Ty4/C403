/* by Tyler Davidson
 *
 * What Goes Up:    NONTRIVIAL      (Dynamic Programming)
 *
*/

#include <algorithm>
#include <iostream>

using namespace std;

int inputList[1000000], M[1000000], M_id[1000000], subsequence[1000000];

void outputSequence(int end)
{
    if (end < 0) return;
    outputSequence(subsequence[end]);
    cout << inputList[end] << endl;
}

int main()
{
    int L = 0, L_end = 0;
    for (int i = 0; cin >> inputList[i]; ++i) {

        int pos = lower_bound(M, M + L, inputList[i]) - M;
        M[pos] = inputList[i];
        M_id[pos] = i;
        subsequence[i] = pos > 0 ? M_id[pos - 1] : -1;
        if(pos == L) {
            L++;
            L_end = i;
        }
    }
    cout << L << "\n-\n";
    outputSequence(L_end);
}
