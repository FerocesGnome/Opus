/* Реализация поиска эйлерова цикла в графе */
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

int V;
int** G = new int*[V]; //матрица смежности

int main()
{

    cin >> V;
    for (int i = 0; i < V; i++)
    {
        G[i] = new int[V];
        for (int j = 0; j < V; j++)
            cin >> G[i][j];
    }

    vector<int> deg (V);
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
            if (j != i)
                deg[i] += G[i][j];
    }

    int first = 0;
    while (!deg[first])
        ++first;

    int v1 = -1,  v2 = -1;
    bool bad = false;
    for (int i = 0; i < V; ++i)
        if (deg[i]%2 == 1)
        {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
        }

    if (v1 != -1)
        ++G[v1][v2],  ++G[v2][v1];

    stack<int> st;
    st.push (first);
    vector<int> res;
    while (!st.empty())
    {
        int v = st.top();
        int i;

        for (i = 0; i < V; ++i){
            if (G[v][i] != 0)
                break;
        }
        if (i == V)
        {
            res.push_back (v);
            st.pop();
        }
        else
        {
            st.push(i);
            --G[v][i];
            --G[i][v];
        }
    }

    if (v1 != -1)
        for (size_t i=0; i + 1 < res.size(); ++i)
            if ((res[i] == v1 && res[i + 1] == v2) || (res[i] == v2 && res[i + 1] == v1))
            {
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back (res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back (res[j]);
                res = res2;
                break;
            }

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            if (G[i][j])
                bad = true;

    if (bad)
        puts ("-1");
    else
        for (size_t i = 0; i < res.size(); ++i)
            printf ("%d ", res[i]+1);

}
