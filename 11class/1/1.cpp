#include <iostream>
#include <vector>

using namespace std;

void Make_adjacency_matrix(vector <pair <int, int> > ribs, int E, int **A)
{
    for (int i = 0; i < E; i++)
    {
        int x = ribs[i].first, y = ribs[i].second;
        x--;
        y--;
        A[x][y]++;
        A[y][x]++;
    }
}

void Print_adjacency_matrix(int **A, int V)
{
    cout << "adjacency matrix:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void Make_incidence_matrix(vector <pair <int, int> > ribs, int E, int **A)
{
    for (int i = 0; i < E; i++)
    {
        int x = ribs[i].first, y = ribs[i].second;
        x--;
        y--;
        A[x][i]++;
        A[y][i]++;
    }
}

void Print_incidence_matrix(int **A, int V, int E)
{
    cout << "incidence matrix:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void Make_adjacency_vector(vector <pair <int, int> > ribs, vector <vector <int> > A, int V, int E)
{
    for (int j = 1; j <= E; j++)
    {
        vector <int> temp;
        for (int i = 0; i < V; i++)
        {
            int First = ribs[i].first;
            int Second = ribs[i].second;
            if (First == j)
                temp.push_back(Second);
            if (Second == j)
                temp.push_back(First);
        }
        A.push_back(temp);
    }
}

void Print_adjacency_vector(vector <vector <int> > A, int E)
{
    cout << "adjacency vector:" << endl;
    for (int i = 0; i < E; i++)
    {
        cout << ++A[i][0] << ": ";
        int Size = A[i].size();
        for (int j = 1; j < Size; j++)
        {
            cout << A[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int V; // кол-во вершин
    cin >> V;
    int E; //кол-во рёбер
    cin >> E;

    vector <pair <int, int> > ribs; //список рёбер

    // считывание списка рёбер
    for (int i = 0; i < E; i++)
    {
        int first = 0, second = 0;
        cin >> first >> second;
        ribs.push_back(make_pair(first, second));
    }

    vector <vector <int> > Adjacency_vector; //вектор смежности

    int** Adjacency_matrix = new int*[V]; //матрица смежности
    for (int i = 0; i < V; i++)
    {
        Adjacency_matrix[i] = new int[V];
        for (int j = 0; j < V; j++)
            Adjacency_matrix [i][j] = 0;
    }

    int** Incidence_matrix = new int*[V]; //матрица инциденции
    for (int i = 0; i < V; i++)
    {
        Incidence_matrix[i] = new int[E];
        for (int j = 0; j < E; j++)
            Incidence_matrix [i][j] = 0;
    }

    Make_adjacency_matrix(ribs, E, Adjacency_matrix);

    Print_adjacency_matrix(Adjacency_matrix, V);

    return 0;
}
