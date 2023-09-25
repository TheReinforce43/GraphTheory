#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 10005;
const int INF = INT_MAX;

vector<pii> gr[N];
vector<pair<pii, int>> list_edges;

int dist[N];

int x, y;

void BellmanFord(int src)
{
    for (int i = 1; i <= x; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int i = 1; i < x; i++)
    {
        for (int u = 1; u <= x; u++)
        {
            for (pii vpair : gr[u])
            {
                int v = vpair.first;
                int w = vpair.second;
                if (dist[u] == INF)
                    continue;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

void BelmanFordUpdate(int src)
{
    for (int i = 1; i <= x; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int i = 1; i < x; i++)
    {
        for (auto edge : list_edges)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if (dist[u] == INF)
                continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

void Print_list()
{
    for (int i = 1; i <= x; i++)
    {
        cout << "dist " << i << " : " << dist[i] << "\n";
    }
}

int main()
{
    cin >> x >> y;

    while (y--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        list_edges.push_back({{u, v}, w});
    }
    BellmanFord(1);
    Print_list();
    cout << "\n\n";
    BelmanFordUpdate(1);
    Print_list();

    return 0;
}