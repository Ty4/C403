/* by Tyler Davidson (From the internet)
 *
 * Robot:       NONTRIVIAL      (Graph Theory)
 *
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int cost[55][55][5];
bool MAP[55][55];
bool vis[55][55][5];

int M, N;

bool free(int x, int y)
{
    if (x <= 0 || y <= 0 || x >= M || y >= N) return false;
    if (MAP[x][y] || MAP[x-1][y] || MAP[x][y-1] || MAP[x-1][y-1]) return 0;
    return true;
}

struct node
{
    int x,y,Dir;

    node(int a, int b,int c){
        x = a;
        y = b;
        Dir = c;
    }
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    while (cin >> M >> N){
        if (M == 0 && N == 0) break;

        int startX, startY, destX, destY, dir;
        char W[10];

        for (int i = 0; i < M; ++i){
            for (int j = 0; j < N; ++j){
                int value;
                cin >> value;
                MAP[i][j]=value;

                for (int k = 0; k < 5; ++k){
                    vis[i][j][k] = false;
                    cost[i][j][k] = 1000000000;
                }
            }
        }

        cin >> startX >> startY >> destX >> destY >> W;
        if (W[0]=='n') dir = 0;
        else if (W[0]=='e') dir = 1;
        else if (W[0]=='s') dir = 2;
        else dir = 3;

        if (free(startX,startY)==0||free(destX,destY)==0)
            cout << "-1" << endl;
        else{
            queue<node> Graph;

            Graph.push(node(startX,startY,dir));
            cost[startX][startY][dir]=0;
            vis[startX][startY][dir]=1;

            int ans = -1;
            while (!Graph.empty()){

                node top=Graph.front();
                Graph.pop();

                if (top.x==destX && top.y==destY){
                    ans=cost[destX][destY][top.Dir];
                    break;
                }

                int r,l,in;
                r=top.x,l=top.y;
                in=top.Dir;
                for (int i=1; i<=3; ++i){
                    if (free( r+(dx[in]*i) , l+(dy[in]*i) )==0)break;
                    if (!vis[r+(dx[in]*i)][l+(dy[in]*i)][in]){
                        vis[r+(dx[in]*i)][l+(dy[in]*i)][in]=1;
                        cost[r+(dx[in]*i)][l+(dy[in]*i)][in]=cost[top.x][top.y][top.Dir]+1;
                        Graph.push(node(r+(dx[in]*i),l+(dy[in]*i),in) );
                    }
                }

                node L(top.x,top.y,(top.Dir+1)%4);
                node R(top.x,top.y,(top.Dir+3)%4);


                if (!vis[L.x][L.y][L.Dir]){
                    cost[L.x][L.y][L.Dir]=cost[top.x][top.y][top.Dir]+1;
                    vis[L.x][L.y][L.Dir]=1;

                    Graph.push(L);
                }

                if (!vis[R.x][R.y][R.Dir]){
                    cost[R.x][R.y][R.Dir]=cost[top.x][top.y][top.Dir]+1;
                    vis[R.x][R.y][R.Dir]=1;

                    Graph.push(R);
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}
