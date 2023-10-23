#include <bits/stdc++.h>
#define pi pair<int, int>
#define N 10050
using namespace std;

vector<pi> gr[N];
vector<pair<pi, int>> edge_list;
bool vis[N];

int minimum_cost = 0;

class edge
{
public:
    int a, b, w;
    edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(edge a, edge b)
    {
        return a.w > b.w;
    }
};

void prims_mst(int src)
{
    priority_queue<edge, vector<edge>, cmp> pq;
    pq.push(edge(src, src, 0));
    vector<edge> edge_list;
    while (!pq.empty())
    {
        edge row = pq.top();
        pq.pop();
        int parent = row.a;
        int child = row.b;
        if (vis[child])
            continue;
        edge_list.push_back({row});
        vis[child] = true;
        for (pi vpair : gr[child])
        {
            int v = vpair.first;
            int w = vpair.second;
            if (vis[v])
                continue;
            pq.push(edge(child, v, w));
        }
    }
    edge_list.erase(edge_list.begin());
    for (edge value : edge_list)
    {
        cout << value.a << " " << value.b << " " << value.w << "\n";
        minimum_cost += value.w;
    }
}

int main()
{
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
    prims_mst(src);

    cout << minimum_cost << "\n";

    return 0;
}