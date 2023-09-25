#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 10;
const int N = 10050;
vector<pii> gr[N];
vector<bool> vis(N);
vector<int> dist(N, INF);

void Dijkstra(int source)
{
    dist[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        vis[u] = true;

        for (pii vpair : gr[u])
        {
            int v = vpair.first;
            int w = vpair.second;
            if (vis[v])
                continue;

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

    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    Dijkstra(1);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist " << i << " : " << dist[i] << endl;
    }

    return 0;
}