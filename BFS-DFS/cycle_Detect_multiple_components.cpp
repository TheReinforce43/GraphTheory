#include <bits/stdc++.h>
using namespace std;
const int N = 10050;

vector<int> gr[N];

bool vis[N];

bool is_cycle(int source, int parent=-1)
{
    vis[source] = true;
    bool cycleDetect = false;

    for (int v : gr[source])
    {
        if (v == parent)
            continue;
        if (vis[v])
            return true;

        cycleDetect = cycleDetect | is_cycle(v, source);
    }

    return cycleDetect;
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

    bool cycleDetect = false;
    for (int i = 1; i <= vertex; i++)
    {
        if (vis[i])
            continue;
        cycleDetect |= is_cycle(i);
    }

    if (cycleDetect)
        cout << "Cycle Detected\n";
    else
        cout << "Not Cycle Detected\n";
    return 0;
}