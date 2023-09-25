#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
vector<int> gr[N];
bool vis[N];

bool is_cycle(int s, int p)
{
    vis[s] = true;
    bool cycleDetect = false;
    for (int v : gr[s])
    {
        if (v == p)
            continue;

        if (vis[v])
            return true;

        cycleDetect = cycleDetect | is_cycle(v, s);
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
    }

    if (is_cycle(1, -1))
    {
        cout << "Cycle Detected\n";
    }
    else
        cout << "Not Cycle Detected\n";

    return 0;
}