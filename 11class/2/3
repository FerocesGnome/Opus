/* Проверить является ли граф деревом */

#include <iostream>

using namespace std;

int V, counter = 0;
bool *used = new bool[V]; //вспомогательный массив
int** G = new int*[V]; //матрица смежности

void dfs(int N)
{
    used[N] = 1;
    for(int i = 0; i < V; i++)
    {
        if ((!used[i])&&(G[N][i]==1))
            dfs(i);
    }
}

bool tree_whether(){
    dfs(0);
    for(int i = 0; i < V; i++)
        if (used[i] == 0){
        counter++;
    }
    return !counter;
}

int main()
{
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        G[i] = new int[V];
        for (int j = 0; j < V; j++)
            cin >> G[i][j];
    }

    bool X = tree_whether();

    cout << X;
    return 0;
}
