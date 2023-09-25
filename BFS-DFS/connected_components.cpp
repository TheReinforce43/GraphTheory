#include <bits/stdc++.h>
using namespace std;

const int N = 100050;

vector<int> gr[N];
bool vis[N];

void BFS(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : gr[u])
        {
            if (vis[v])
                continue;
            vis[v] = true;
            q.push(v);
        }
    }
}
int main()
{

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
    }
    int comp = 0;

    for (int i = 1; i <= v; i++)
    {
        if (vis[i])
        {
            cout<<i<<" ,";
            continue;
        }
            
        cout<<endl;
        cout<<"Component "<<i<<" : ";
        comp++;
        BFS(i);
    }

   cout << "\nNumber of Components "
         << " : " << comp << "\n";

    return 0;
}