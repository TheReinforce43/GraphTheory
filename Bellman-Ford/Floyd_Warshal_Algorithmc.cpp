#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9 + 7;

typedef pair<int, int> pii;
int dist[N][N];
vector<pii> gr[N];
int x, y;

void Initial()
{

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (i == j)
                dist[i][i] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

void print_value()
{
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (dist[i][j] == INF)
                cout << "x ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void Floyd_Warshall()
{
    for (int k = 1; k <= x; k++)
    {
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main()
{

    cin >> x >> y;

    Initial();

    for (int i = 0; i < y; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    print_value();

    Floyd_Warshall();
    cout << "\n\n";
    print_value();

    return 0;
}