#include <bits/stdc++.h>
#define pi pair<int, int>
#define inf INT_MAX

using namespace std;

const int N = 100050;
vector<pi> gr[N];
bool vis[N];
int dist[N];
int parent[N];

void init()
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = inf;
    }
}

void dijkstra(int s)
{
    dist[s] = 0;
    parent[s] = -1;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({dist[s], s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        vis[u] = true;

        for (pi vpair : gr[u])
        {
            int v = vpair.first;
            int w = vpair.second;
            if (vis[v])
                continue;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}

int main()
{
    init();

    int vertex, edge;
    cin >> vertex >> edge;

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    int src;
    cin >> src;
    dijkstra(src);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist "
             << " : " << dist[i] << "\n";
    }

    return 0;
}