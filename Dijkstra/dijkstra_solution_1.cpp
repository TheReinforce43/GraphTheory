#include <bits/stdc++.h>
#define INF 1e9 + 7
using namespace std;
typedef pair<int, int> pi;

const int N = 10050;
bool vis[N];
vector<pi> gr[N];
int dist[N];
int parent[N];

void init()
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
    }
}

void Dijkstra(int s)
{
    // vis[s]=true;
    dist[s] = 0;
    parent[s] = -1;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({dist[s], s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;

        for (pi vpair : gr[u])
        {
            int v = vpair.first;
            int w = vpair.second;

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
    Dijkstra(src);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist "
             << " : " << dist[i] << "\n";
    }

    return 0;
}