/* Поиск шарниров в графе */
#include <iostream>
#include <vector>

using namespace std;

int V;
int** G = new int* [V]; //матрица смежности
bool *used = new bool[V];
int timer;
int *Tin = new int[V];
int *Fup = new int[V];
bool *cutpoints = new bool[V];

void is_cutpoint(int v){
    cutpoints[v] = true;
}

void dfs(int v, int p = -1){
    used[v] = true;
    Tin[v] = Fup[v] = timer++;
    int children = 0;
    for (int i = 0; i < V; i++){
        if (G[v][i] != 0){
            int to = i;
            if (to == p) continue;
            if (used[to])
                Fup[v] = min (Fup[v], Tin[to]);
            else{
                dfs(to, v);
                Fup[v] = min (Fup[v], Fup[to]);
                if (Fup[to] >= Tin[v] && p != -1)
                    is_cutpoint(v);
                ++children;
            }
        }
    }
    if (p == -1 && children > 1)
        is_cutpoint(v);
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

    timer = 0;
	for (int i = 0; i < V; ++i)
		used[i] = false;
	dfs (0);

	for (int i = 0; i < V; i++){
        if (cutpoints[i] == true)
            cout << i+1 << " ";
	}
}
