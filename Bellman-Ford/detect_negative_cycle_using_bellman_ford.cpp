#include <bits/stdc++.h>
#define pi pair<int, int>
#define N 1005
using namespace std;

const int inf = 1e9 + 7;
vector<pair<pi, int>> list_of_edge;
int dist[N];
int vertex, edge;

void init()
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = inf;
    }
}

void Bellman_ford(int src)
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

bool is_cycle()
{
    for (pair<pi, int> dpair : list_of_edge)
    {
        int u = dpair.first.first;
        int v = dpair.first.second;
        int w = dpair.second;
        if (dist[v] > dist[u] + w)
            return true;
    }
    return false;
}

int main()
{

    init();

    cin >> vertex >> edge;

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        list_of_edge.push_back({{u, v}, w});
    }

    int src;
    cin >> src;
    Bellman_ford(src);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist "
             << " : " << dist[i] << "\n";
    }
    if (is_cycle())
        cout << "cycle detected\n";
    else
        cout << "cycle not detected\n";

    return 0;
}