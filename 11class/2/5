/* Найти кратчайший путь между двумя вершинами */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V;
bool* used = new bool[V]; //вспомогательный массив
int* P = new int [V]; //массив предков
int* Dist = new int [V]; // ещё один массив
int** G = new int*[V]; //матрица смежности

void bfs(int N)
{
    used[N] = 1;
    P[N] = N;
    Dist[N] = 0;
    queue<int> q;
    q.push(N);
    while (!q.empty())
    {
        int N = q.front();
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if ((G[N][i])&&(!used[i]))
            {
                used[i] = true;
                P[i] = N;
                Dist[i] = Dist[N] + 1;
                q.push(i);
            }
        }
    }
}

void print_way(int N) {
  if (P[N] != N) {
    print_way(P[N]);
  }
  cout << N+1 << ' ';
}

void search_ways(int from, int to){
    bfs(from);
    print_way(to);
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

    int from, to;
    cin >> from >> to;

    search_ways(from - 1, to - 1);

    return 0;
}
