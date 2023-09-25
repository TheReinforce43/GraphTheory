#include <bits/stdc++.h>

using namespace std;

const int N = 10050;
vector<int> gr[N];
bool vis[N];
int level[N];
int parent[N] = {-1};

void BFS(int s)
{
    vis[s] = true;
    parent[s] = -1;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : gr[u])
        {
            if (vis[v])
                continue;
            parent[v] = u;
            q.push(v);
            level[v] = level[u] + 1;
            vis[v] = true;
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

    int s, d;
    cin >> s >> d;
    BFS(s);
    cout << "Shortest Path : " << level[d] << "\n";

    /*  for (int i = 1; i <= vertex; i++)
     {
         cout << "parent " << i << " : " << parent[i] << "\n";
     }  */

    vector<int> path;
    int curr = d;

    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    cout << "Path : " << endl;
    for (auto value : path)
        cout << value << " ";

    return 0;
}