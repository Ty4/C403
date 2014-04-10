/* by Tyler Davidson
 *
 * Arbitrage (II):      (Dynamic Programming)
 *
 */

#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

double max(const double & num1, const double & num2)
{
    return num1 > num2 ? num1 : num2;
}

int main(){
    int n, m;
    int caseNumber=1;
    double M[30][30];
    map<string, int> indexOfCurrency;
    string currencyA,currencyB;
    double exchangeRate;
    bool exists;

    cin >> n;
    while(n != 0){
        indexOfCurrency.clear();

        for(int i = 0; i < n; ++i){
            cin >> currencyA;
            indexOfCurrency[currencyA] = i;
        }

        memset(M, 0, sizeof(M));

        cin >> m;

        for(int i = 0; i < m; ++i){
            cin >> currencyA >> exchangeRate >> currencyB;
            M[indexOfCurrency[currencyA]][indexOfCurrency[currencyB]] = exchangeRate;
        }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    M[i][j] = max(M[i][j], M[i][k]*M[k][j]);

        exists = false;

        for(int i = 0; i < n; ++i)
            if(M[i][i] > 1.0)
                exists = true;

        cout << "Case " << caseNumber << ": ";
        caseNumber++;

        if(exists) cout << "Yes" << endl;
        else cout << "No" << endl;

        cin >> n;
    }

    return 0;
}
