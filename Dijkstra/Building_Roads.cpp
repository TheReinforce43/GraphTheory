#include <bits/stdc++.h>
using namespace std;

const int N = 100050;
vector<int> gr[N];
bool vis[N];

void DFS(int s)
{
    vis[s] = true;
    for (int v : gr[s])
    {
        if (vis[v])
            continue;
        DFS(v);
    }
}

int main()
{

    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<int> leader;

    for (int i = 1; i <= vertex; i++)
    {
        if (vis[i])
            continue;
        DFS(i);
        leader.push_back(i);
    }
    cout << leader.size() - 1 << "\n";
    for (int i = 1; i < leader.size(); i++)
    {
        cout << leader[i - 1] << " " << leader[i] << "\n";
    }

    return 0;
}