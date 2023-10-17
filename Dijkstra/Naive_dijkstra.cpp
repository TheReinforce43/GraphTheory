#include <bits/stdc++.h>
using namespace std;

const int N = 100050;
const int INF = 1e9 + 7;
vector<pair<int, int>> gr[N];
int dist[N];


void init()
{
    for (int i = 0; i <= N; i++)
    {
        dist[i] = INF;
    }
}

void Naive_dijkstra(int s)
{
    queue<int> que;
    dist[s] = 0;
    que.push(s);

    while (!que.empty())
    {
        int u = que.front();
        que.pop();
      
        for (pair<int, int> upair : gr[u])
        {
            int v = upair.first;
            int w = upair.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                que.push(v);
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

    int src, dst;
    cin >> src;
    Naive_dijkstra(src);

    for (int i = 1; i <= vertex; i++)
    {
        cout << "dist " << i << " : " << dist[i] << "\n";
    }

    return 0;
}