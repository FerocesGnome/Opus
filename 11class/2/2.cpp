/* Проверка находятся ли две вершины в одной компоненте связности */

#include <iostream>

using namespace std;

int V, counter = 0;
bool *used = new bool[V]; //вспомогательный массив
int** G = new int*[V]; //матрица смежности
int from, to;

void dfs(int N)
{
    used[N] = 1;
    for(int i = 0; i < V; i++)
    {
        if ((!used[i])&&(G[N][i]==1)){
            if (i == to - 1) counter++;
            dfs(i);
        }
    }
}

bool connection_of_two_vertices(int from, int to)
{
    dfs(from - 1);
    return counter;
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
    cin >> from >> to;

    bool X = connection_of_two_vertices(from, to);

    cout << X;

    return 0;
}
