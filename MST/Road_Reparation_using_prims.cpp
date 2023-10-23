#include <bits/stdc++.h>
#define pi pair<int, int>

using namespace std;
const int N = 2 * 1e5 + 50;
vector<pi> gr[N];
long long int min_value = 0;
bool vis[N];

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

void minimum_cost(int src)
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
        vis[child] = true;
        edge_list.push_back(row);
        for (pi vpair : gr[child])
        {
            int v = vpair.first;
            int w = vpair.second;
            if (vis[v])
                continue;
            pq.push(edge(child, v, w));
        }
    }

    for (edge value : edge_list)
    {
        min_value += value.w;
    }
}

int main()
{

    int vertex, edge;
    cin >> vertex >> edge;
    bool flag = false;

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
        }
    minimum_cost(1);

    for (int i = 1; i <= vertex; i++)
    {
        if (vis[i] == false)
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "IMPOSSIBLE\n";
    else
        cout << min_value << "\n";
    return 0;
}