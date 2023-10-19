#include <bits/stdc++.h>
#define pi pair<int, int>
#define N 1005
using namespace std;

const int inf = 1e9 + 7;

vector<pi> gr[N];
int dist[N];

int vertex, edge;

void Bellman_ford(int src)
{
    dist[src] = 0;

    for (int i = 1; i <= vertex; i++)
    {
        for (int u = 1; u < vertex; u++)
        {
            for (pi vpair : gr[u])
            {

                int v = vpair.first;
                int w = vpair.second;
                if (dist[u] == inf)
                    continue;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

void init()
{
    for (int i = 1; i <= N; i++)
        dist[i] = inf;
}

int main()
{

    init();

    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        // gr[v].push_back({u, w});
    }
    int src;
    cin >> src;
    Bellman_ford(src);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist " << i << " : " << dist[i] << "\n";
    }

    return 0;
}