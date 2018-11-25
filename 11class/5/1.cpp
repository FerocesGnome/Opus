/* Проверить является ли граф двудольным */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V;
bool* used = new bool[V]; //вспомогательный массив
int** G = new int*[V]; //матрица смежности
vector <int> part; //принадлежность какой-либо доле
int A = 0; //переменная отвечающая за запись в доли
int B = 0; //переменная отвеающая за то что наш граф делится на две части

int change (int N){
    if (N == 0)
        N = 1;
    else
        N = 0;
    return N;
}

void modified_bfs (int N)
{
    part[N] = A;
    used[N] = 1;
    queue<int> q;
    q.push(N);

    cout << endl << "! ";
    while (!q.empty())
    {
        int N = q.front();
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if ((G[N][i]) && (!used[i]))
            {
                used[i] = true;
                q.push(i);
                int temp = change(A);
                part[i] = temp;
            }

            if ((G[N][i]) && (used[i]) && (part[i] == part[N]))
            {
                B++;
            }
        }
        A = change(A);
    }
}

void check_on_bipartition(int N){
    modified_bfs(N);
    if (B == 0) cout << "can be divided";
    else cout << "cannot be divided";
}

int main()
{
    cin >> V;

    for (int i = 0; i < V; i++)
    {
        part.push_back(1);
        G[i] = new int[V];
        for (int j = 0; j < V; j++)
            cin >> G[i][j];
    }

    check_on_bipartition(0);

    return 0;
}
