#include <bits/stdc++.h>
using namespace std;

const int N = 10050;
vector<int> gr[N];
bool vis[N];
vector<int> compnt;

void DFS(int s)
{
    vis[s] = true;
    compnt.push_back(s);
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

    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    int cnt = 0;

    for (int i = 1; i <= vertex; i++)
    {
        if (vis[i])
            continue;
        cnt++;
        DFS(i);

        for (int value : compnt)
        {
            cout << value << " ";
        }
        cout << endl;
        compnt.clear();
    }

    return 0;
}