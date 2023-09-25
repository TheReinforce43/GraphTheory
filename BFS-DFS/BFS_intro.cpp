#include <bits/stdc++.h>
using namespace std;

const int N = 10050;
vector<int> gr[N];
bool vis[N];
int level[N];

void BFS(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        /* code */
        int u = q.front();
        q.pop();
        //cout << u << " ";
        for (int v : gr[u])
        {
            if (vis[v])
                continue;
            q.push(v);
            vis[v];
            level[v] = level[u] + 1;
        }
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
    }
    BFS(1);
    for(int i=1;i<=vertex;i++)
    {
        cout<<"level "<<i<<" : "<<level[i]<<"\n";
    }
    return 0;
}
