/* by Tyler Davidson
 *
 * Airline Comparison:      NONTRIVIAL      (Graph Theory)
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 128;

vector<vector<int> > C1(SIZE, vector<int>(SIZE, 0));
vector<vector<int> > C2(SIZE, vector<int>(SIZE, 0));


vector<vector<int> > readInFlights(const int num)
{
    vector<vector<int> > flights(SIZE, vector<int>(SIZE, 0));
    for (int i = 0; i < num; ++i){
        char u, v;
        cin >> u >> v;
        flights[u][v] = 1;
    }

    return flights;
}


void setConnections()
{
    for (int k = 0; k < SIZE; ++k){
        for (int i = 0; i < SIZE; ++i){
            for (int j = 0; j < SIZE; ++j){
                if (C1[i][k] && C1[k][j])
                    C1[i][j] = 1;
                if (C2[i][k] && C2[k][j])
                    C2[i][j] = 1;
            }
        }
    }

}


int main()
{
    int testCases;

    cin >> testCases;

    while (testCases){
        int N, M;
        cin >> N;
        C1 = readInFlights(N);

        cin >> M;
        C2 = readInFlights(M);

        setConnections();

        if (C1 == C2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        if(testCases) cout << endl;

        --testCases;
    }
    return 0;
}
