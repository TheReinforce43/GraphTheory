#include <bits/stdc++.h>
using namespace std;

const int N =  100005+10;
vector<int> gr[N];
int level[N];
int parent[N];
bool vis[N];

void BFS(int s)
{
    vis[s] = true;
    queue<int> que;
    que.push(s);
    parent[s] = -1;
    level[s] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        for (int v : gr[u])
        {
            if (vis[v])
                continue;
            vis[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
            que.push(v);
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
        gr[v].push_back(u);
    }

    BFS(1);
    
    if (vis[vertex] == false)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        int k = level[vertex] + 1;
        vector<int> ans;
        cout << k << "\n";
        //cout<<level[vertex]<<"\n";
        int s=level[vertex];

        while (s--)
        {
            ans.push_back(vertex);

            vertex = parent[vertex];
        }
        ans.push_back(1);

        reverse(ans.begin(), ans.end());
        
        for (int value : ans)
            cout << value << " ";
        cout << "\n";
    }

    return 0;
}