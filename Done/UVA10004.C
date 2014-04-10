#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool resp;

void dfs(int start, int color, int * colors, vector<int> * graph)
{

	 if(colors[start] != 0){
		if(!(color == colors[start]))
			resp=false;
	}
	else {
		colors[start]=color;

		for(int i=0;i<graph[start].size();i++){
			int color2 = (color == 1) ? 2 : 1;
			dfs(graph[start][i],color2,colors,graph);
		}
	}
}

int main()
{
	int nods,edges,a,b;

	while (cin >> nods, nods){
		vector <int> graph[nods];
		int colors[nods];

		cin >> edges;

		memset(colors,0,sizeof colors);

		for (int i = 0; i < edges; ++i){
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		resp = true;

		dfs(0,1,colors,graph);

		if (resp) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;

	}

 return 0;
}
