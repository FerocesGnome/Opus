/* Осуществить топологическую сортировку */

#include <iostream>
#include <vector>

using namespace std;

int V, counter = 0;
bool *used = new bool[V]; //вспомогательный массив
vector <int> ans; //массив с позициями
int** G = new int*[V]; //матрица смежности

void modified_dfs(int N)
{
    used[N] = 1;
    for(int i = 0; i < V; i++)
    {
        if ((!used[i])&&(G[N][i]==1))
            modified_dfs(i);
    }
    ans.push_back(N + 1);
}

void Topological_sorting()
{
	for (int i = 0; i < V; ++i)
		if (!used[i])
			modified_dfs (i);
	vector <int> help;
	for (int i = 0; i < ans.size(); i++){
        help.push_back(ans[i]);
	}
	for (int i = 0; i < ans.size(); i++){
        ans[ans.size() - 1 - i] = help[i];
	}
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

    Topological_sorting();

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
