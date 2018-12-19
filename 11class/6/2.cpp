/* Алгоритм Дейкстры */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n;
    int** g = new int*[n]; // Матрица пропускных способнотей
    const int INF = 1e9; // значение "бесконечность"
    cin >> n;

    int dist[n]; // минимальное расстояние
    bool visit[n]; // посещенные вершины
    int temp;
    int minindex, min;

    // Инициализация матрицы связей
    for (int i = 0; i < n; i++)
    {
        g[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int start = 0; // начальная вершина
    int end = 0; // конечная вершины
    cin >> start;
    start--;
    cin >> end;

    //Инициализация вершин и расстояний
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visit[i] = 1;
    }
    dist[start] = 0;

    // Шаг алгоритма
    do
    {
        minindex = INF;
        min = INF;
        for (int i = 0; i < n; i++)
        {
            // Если вершину ещё не обошли и вес меньше min
            if ((visit[i] == 1) && (dist[i] < min))
            {
                // Переприсваиваем значения
                min = dist[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != INF)
        {
            for (int i = 0; i < n; i++)
            {
                if (g[minindex][i] > 0)
                {
                    temp = min + g[minindex][i];
                    if (temp < dist[i])
                    {
                        dist[i] = temp;
                    }
                }
            }
            visit[minindex] = 0;
        }
    }  while (minindex < INF);

    cout << ".";

    // Вывод кратчайших расстояний до вершин
    for (int i = 0; i < n; i++){
        cout << "Dist. " << i+1 << "= " << dist[i] << endl;
    }

    // Восстановление пути
    int ver[n]; // массив посещенных вершин

    ver[0] = end; // начальный элемент - конечная вершина
    end--;
    int k = 1; // индекс предыдущей вершины
    int weight = dist[end]; // вес конечной вершины

    while (end > 0) // пока не дошли до начальной вершины
    {
        for(int i = 0; i < n; i++) // просматриваем все вершины
            if (g[end][i] != 0)   // если связь есть
            {
                int temp = weight - g[end][i]; // определяем вес пути из предыдущей вершины
                if (temp == dist[i]) // если вес совпал с рассчитанным
                {
                    // значит из этой вершины и был переход
                    weight = temp; // сохраняем новый вес
                    end = i;       // сохраняем предыдущую вершину
                    ver[k] = i + 1; // и записываем ее в массив
                    k++;
                }
            }
    }
    // Вывод пути
    for (int i = k - 1; i >= 0; --i){
        cout << ver[i] << " ";
    }
    return 0;
}
