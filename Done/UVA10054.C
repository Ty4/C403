/* by Tyler Davidson
 *
 * The Necklace:		NONTRIVIAL		(Graph Theory)
 *
*/

#include <iostream>
#include <string.h>

#define SIZE 52

using namespace std;

int adj[SIZE][SIZE];
int degree[SIZE], list[15000], indx;

// Modified from Competitive Programming 3
void EulerTour(int u, int n){
    int i;

    for (i = 1 ; i <= n ; ++i){
        if (adj[u][i]){
            adj[u][i]--;
            adj[i][u]--;
            EulerTour(i, n);
            list[indx++] = u;
        }
    }
}

void printNecklace(int n, int m){
    int i;

    indx = 0;
    for (i = 0 ; i < SIZE ; ++i) if (degree[i]) break;
    EulerTour(i, n);

    if (indx != m){
        cout << "some beads may be lost" << endl;
        return;
    }
    list[indx] = list[0];
    for (i = 0 ; i < indx ; ++i)
    	cout << list[i] << " " << list[i+1] << endl;
}

int main(){
    int testCases, kase, n, u, v, m, i;

    cin >> testCases;
	kase = 1;
    while(testCases--){

        for (cin >> m, i = n = 0 ; i < m ; ++i){
        	cin >> u >> v;
            if (u > n) n = u;
            if (v > n) n = v;
            adj[u][v]++, adj[v][u]++;
            degree[u]++, degree[v]++;
        }

        for (i = 1 ; i <= n ; ++i){
            if (degree[i] & 1) break;
        }

        cout << "Case #" << kase << endl;
        if (i <= n) cout << "some beads may be lost" << endl;
        else printNecklace(n, m);

        memset(adj, 0, sizeof(adj));
        memset(degree, 0, sizeof(degree));

        if (testCases) cout << endl;
        ++kase;
    }

    return 0;
}
