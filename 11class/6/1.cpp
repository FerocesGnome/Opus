/* Алгоритм Прима */
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    // входные данные
int n = 0;
int** g = new int*[n]; //матрица смежности
const int INF = 1e9; // значение "бесконечность"
cin >> n;

for (int i = 0; i < n; i++){
    g[i] = new int[n];
    for (int j = 0; j < n; j++){
        cin >> g[i][j];
        if (g[i][j] == 0) g[i][j] = INF;
    }
}

// алгоритм Прима
vector <bool> used (n); //использованные вершины
vector <int> mindist (n, INF); //мин. расстояния до вершин
vector <int> sel_e (n, -1); // массив предков

int sum = 0; //начальная сумма 0
mindist[0] = 0; // раст. из ребра в само себя

for (int i = 0; i < n; ++i) {
	int v = -1;
	for (int j = 0; j < n; ++j)
		if (!used[j] && (v == -1 || mindist[j] < mindist[v])) //ребро с мин. стоимостью
			v = j;
        if (mindist[v] == INF) { //если не связный
            cout << "No way!";
            exit(0);
        }

	used[v] = true; // вершина V пройдена

	//вывод списка рёбер остовного дерева на экран
	if (sel_e[v] != -1){
		cout << sel_e[v]+1 << " " << v+1 << endl;
		sum += g[v][sel_e[v]]; // сумма всех рёбер ост. дерева
	}

	for (int to = 0; to < n; ++to) //изменение мин. расстояний
		if (g[v][to] < mindist[to]) {
			mindist[to] = g[v][to];
			sel_e[to] = v;
		}
}

cout << sum;

    return 0;
}
