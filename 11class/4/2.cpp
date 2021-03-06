/* Поиск мостов в графе */
#include <iostream>
#include <vector>

using namespace std;

int V;
int** G = new int* [V]; //матрица смежности
bool *used = new bool[V];
int timer;
int *Tin = new int[V];
int *Fup = new int[V];
vector <pair<int, int> > bridges;

void is_bridge(int v, int to){
    bridges.push_back(make_pair(v, to));
}

void dfs(int v, int p = -1){
    used[v] = true;
    Tin[v] = Fup[v] = timer++;
    for (int i = 0; i < V; i++){
        if (G[v][i] != 0){
            int to = i;
            if (to == p) continue;
            if (used[to])
                Fup[v] = min (Fup[v], Tin[to]);
            else{
                dfs(to, v);
                Fup[v] = min (Fup[v], Fup[to]);
                if (Fup[to] > Tin[v] && p!= -1)
                    is_bridge(v, to);
            }
        }
    }
    if (p == -1){
        for (int i = 0; i < V; i++){
            if ((G[v][i] != 0) && (i != v)){
                is_bridge(v, i);
            }
        }
    }
}

void find_bridges() {
	timer = 0;
	for (int i = 0; i < V; ++i)
		used[i] = false;
	for (int i = 0; i < V; ++i)
		if (!used[i])
			dfs (i);
}

int main()
{
    /*чтение графа в матрицу смежности*/

    cin >> V;
    for (int i = 0; i < V; i++)
    {
        G[i] = new int[V];
        for (int j = 0; j < V; j++)
            cin >> G[i][j];
    }

	find_bridges();

	for (size_t i = 0; i < bridges.size(); i++){
            cout << bridges[i].first + 1 << ", " << bridges[i].second + 1 << "; ";
	}
}
