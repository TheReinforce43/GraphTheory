#include <bits/stdc++.h>
using namespace std;

const int N = 100050;
vector<int> gr[N];
bool vis[N];

int depth[N];
int height[N];

void DFS(int s)
{
    vis[s] = true;
    // cout << "Visited node : " << s << "\n";
    for (int v : gr[s])
    {
        if (vis[v])
            continue;
        depth[v] = depth[s] + 1;
        DFS(v);

        // if (height[v] + 1 > height[s])
        //  {
        //    height[s] = height[v] + 1;
        // }

        height[s] = max(height[s], height[v] + 1);
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

    DFS(1);

    for (int i = 1; i <= vertex; i++)
    {
        //  cout << "vertex " << i << " : "
        //     << "status : " << vis[i] << "\n";

        cout << "depth " << i << " : " << depth[i] << " , ";
        cout << "Height " << height[i] << "\n";
    }

    return 0;
}