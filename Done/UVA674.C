/* by Tyler Davidson
 *
 * Coin Change:     (Dynamic Programming)
 *
 * This is a straightforward DP algorithm utilizing the fact the the number
 *    of ways to make change for a given amount n is directly related to the
 *    number of ways to make change for n-1.
 */

#include <iostream>

using namespace std;

long ways[7500];
void count ()
{

    int coinDenoms[] = { 50, 25, 10, 5, 1 };

    ways [0] = 1;

    for (int i = 0; i < 5; ++i) {
        for (int j = coinDenoms[i]; j < 7500; ++j)
            ways[j] += ways [j - coinDenoms[i]];
    }
}

int main ()
{
    count ();
    int n;
    while (cin >> n)
        cout << ways[n] << endl;

    return 0;
}
