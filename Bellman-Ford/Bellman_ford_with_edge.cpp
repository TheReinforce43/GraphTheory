#include <bits/stdc++.h>
#define pi pair<int, int>
#define N 1005
using namespace std;

const int inf = 1e9 + 7;
vector<pi> gr[N];
vector<pair<pi, int>> list_of_edge;
int dist[N];

void init()
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = inf;
    }
}

int vertex, edge;

void bellman_ford(int src)
{
    dist[src] = 0;

    for (int i = 1; i < vertex; i++)
    {
        for (pair<pi, int> dpair : list_of_edge)
        {
            int u = dpair.first.first;
            int v = dpair.first.second;
            int w = dpair.second;
            if (dist[u] == inf)
                continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main()
{

    init();

    cin >> vertex >> edge;

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // gr[u].push_back({v, w});
        list_of_edge.push_back({{u, v}, w});
    }
    int src;
    cin >> src;
    bellman_ford(src);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist "
             << " : " << dist[i] << "\n";
    }

    return 0;
}