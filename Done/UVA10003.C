/* by Tyler Davidson
 *
 * Cutting Sticks:      (Dynamic Programming)
 *
 */

#include <iostream>

#define INT_MAX 2147483647

using namespace std;

int lengthOfStick, numberOfCuts;
int cuts[50 + 3];
int costTable[50 + 3][50 + 3];

int calcCosts(int left, int right)
{
    if (left + 1 == right) return 0;

    if (costTable[left][right] != -1)
        return costTable[left][right];

    int cost = 0;
    int minimum = INT_MAX;

    for (int i = left + 1; i < right; i++) {
        cost = calcCosts(left, i) + calcCosts(i, right) + cuts[right] - cuts[left];
        if (cost < minimum) minimum = cost;
    }

    return costTable[left][right] = minimum;
}

void reset()
{
    for (int i = 0; i < 53; i++) {
        for (int j = 0; j < 53; j++)
            costTable[i][j] = -1;
    }
}

int main()
{
    cin >> lengthOfStick;
    while (lengthOfStick) {
        cin >> numberOfCuts;

        for (int i = 1; i <= numberOfCuts; ++i)
            cin >> cuts[i];

        cuts[0] = 0;
        cuts[numberOfCuts+1] = lengthOfStick;

        reset ();

        cout << "The minimum cutting is " << calcCosts(0, numberOfCuts+1) << "." << endl;

        cin >> lengthOfStick;
    }

    return 0;
}
