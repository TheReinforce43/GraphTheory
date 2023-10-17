#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 10050;
const int INF = 1e9 + 7;

vector<pii> gr[N];
vector<int> dist(N, INF);
bool vis[N];
vector<pii> parent;

void shortest_path(int s)
{
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({dist[s], s});
    parent.push_back({s, -1}); // children,parent

    while (!pq.empty())
    {
        pii pr = pq.top();
        pq.pop();

        int pr_ver = pr.second;
        if (vis[pr_ver])
            continue;
        vis[pr_ver] = true;
        for (pii ch_pair : gr[pr_ver])
        {
            int child = ch_pair.first;
            int w = ch_pair.second;

            if (dist[child] > dist[pr_ver] + w)
            {
                dist[child] = dist[pr_ver] + w;
                pq.push({dist[child], child});
                parent.push_back({child, pr_ver});
            }
        }
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

    int src, dst;
    cin >> src >> dst;

    shortest_path(src);

    /* for (int i = 1; i <= vertex; i++)
    {
        cout << "dist " << i << " : " << dist[i] << "\n";
    } */

    vector<int> path;

    if (vis[dst] == false)
    {
        cout << "Shortest path not found\n";
        return 0;
    }

    while (dst != -1)
    {
        path.push_back(dst);
        dst = parent[dst].second;
    }

    path.push_back(src);

    for (auto value : path)
        cout << value << " ";

    return 0;
}