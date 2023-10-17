#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 100050;
const int INF = 1e9 + 7;
int dist[N];
vector<pii> gr[N];
bool vis[N];

void init()
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
}

void optimized_dijkstra(int s)
{
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[s], s});

    while (!pq.empty())
    {
        pii vpair = pq.top();
        pq.pop();

        int u = vpair.second;

        if (vis[u])
            continue;
        vis[u] = true;

        for (pii np : gr[u])
        {
            int v = np.first;
            int w = np.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    init();

    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }
    int src;
    cin >> src;
    optimized_dijkstra(src);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist " << i << " : " << dist[i] << "\n";
    }

    return 0;
}