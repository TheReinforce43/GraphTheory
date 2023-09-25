#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int mat[N][N];

int main()
{

    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
        // mat[v][u] = 1;
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}