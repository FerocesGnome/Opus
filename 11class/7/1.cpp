/* Алгоритм Форда-Фалкерсона */
#include "stdio.h"
#include "conio.h"
#include "iostream"

using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

int n;
int** capacity = new int*[n]; // Матрица пропускных способнотей
int** flow = new int*[n];// Матрица потока
int* color = new int[n];// Цвета для вершин
int* pred = new int[n];// Массив пути
int head = 0, tail = 0;// Начало, Конец
int* Q = new int[21474836];// Очередь, хранящая номера вершин входящих в неё

int min(int x, int y) //Сравнение двух целых значений
{
    if (x < y)
        return x;
    else
        return y;
}

void enque(int x) //Добавить в очередь (мы ступили на вершину)
{
    Q[tail] = x;     // записать х в хвост
    tail++;          // хвостом становиться следующий элемент
    color[x] = GREY; // Цвет серый (из алгоритма поиска)
}

int deque() //Убрать из очереди (Вершина чёрная, на неё не ходить)
{
    int x = Q[head];  // Записать в х значение головы
    head++;           // Соответственно номер начала очереди увеличивается
    color[x] = BLACK; // Вершина х - отмечается как прочитанная
    return x;         // Возвращается номер х прочитанной вершины
}

int bfs(int start, int end) //Поиск в ширину
{
    int u = 0, v;
    for(u; u < n; u++ ) // Сначала отмечаем все вершины не пройденными
        color[u] = WHITE;

    head = 0;   // Начало очереди 0
    tail = 0;   // Хвост 0
    enque(start);      // Вступили на первую вершину
    pred[start]= -1;   // Специальная метка для начала пути
    while(head != tail)  // Пока хвост не совпадёт с головой
    {
        u = deque();       // вершина u пройдена
        for( v = 0; v < n; v++ ) // Смотрим смежные вершины
        {
            // Если не пройдена и не заполнена
            if((color[v] == WHITE) && (capacity[u][v] - flow[u][v] > 0) && capacity[u][v] > 0)
            {
                enque(v);  // Вступаем на вершину v
                pred[v] = u; // Путь обновляем
            }
        }
    }
    if(color[end] == BLACK) // Если конечная вершина, дошли - возвращаем 0
        return 1;
    else
        return 0;
}

int max_flow(int source, int stock) //Максимальный поток из истока в сток
{
    int maxflow = 0;            // Изначально нулевой

    for(int i = 0; i < n; i++ )  // Зануляем матрицу потока
    {
        flow[i] = new int[n];
        for(int  j = 0; j < n; j++)
            flow[i][j] = 0;
    }

    while(bfs(source,stock) == 1)             // Пока сеществует путь
    {
        int delta = 21474836;
        for(int u = n-1; pred[u] >= 0; u = pred[u]) // Найти минимальный поток в сети
        {
            delta = min(delta, (capacity[pred[u]][u] - flow[pred[u]][u]) );
        }
        for(int u = n-1; pred[u] >= 0; u = pred[u]) // По алгоритму Форда-Фалкерсона
        {
            flow[pred[u]][u] += delta;
            flow[u][pred[u]] -= delta;
        }
        maxflow+=delta;                       // Повышаем максимальный поток
    }
    return maxflow;
}

int main()
{
    cin >> n; //количество вершин

    for(int i = 0; i < n; i++)
    {
        capacity[i] = new int[n];
        for(int j = 0; j < n; j++)
            cin >> capacity[i][j];
    }

    int source, stock; //исток и сток
    cin >> source >> stock;
    source--;
    stock--;
    cout << "Maximum flow: " << max_flow(source, stock) << endl;
    cout << "The matrix of the received stream values: " << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << flow[i][j] << " ";
        cout << endl;
    }
    return 0;
}
