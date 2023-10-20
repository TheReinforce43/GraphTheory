#include <bits/stdc++.h>
#define N 1005
using namespace std;

const int inf = 1e9 + 7;
int vertex, edge;
int mat[N][N];

void init(int node)
{
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (i == j)
                mat[i][j] = 0;
            else
                mat[i][j] = inf;
        }
    }
}

void Floyd_Warshal(int node)
{

    for (int k = 1; k <= node; k++)
    {
        for (int i = 1; i <= node; i++)
        {
            for (int j = 1; j <= node; j++)
            {
                if (mat[i][k] == inf || mat[k][j] == inf)
                    continue;
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

void print_value(int node)
{
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (mat[i][j] == inf)
                cout << "inf ";
            else
                cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

bool cycle_detect(int node)
{
    for (int i = 1; i <= node; i++)
    {
        if (mat[i][i] != 0)
            return true;
    }
    return false;
}

int main()
{

    cin >> vertex >> edge;
    init(vertex + 1);

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }

    print_value(vertex);
    Floyd_Warshal(vertex);
    cout << "\nAfter Updated\n";
    print_value(vertex);
    if (cycle_detect(vertex))
        cout << "Cycle detected\n";
    else
        cout << "Cycle not detected\n";

    return 0;
}