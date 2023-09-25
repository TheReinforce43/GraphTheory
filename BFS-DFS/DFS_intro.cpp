#include<bits/stdc++.h>
using namespace std;

const int N=10050;
vector<int> gr[N];
bool vis[N];

void DFS(int s)
{
    if(vis[s]) return;
    vis[s]=true;
    cout<<s<<" ";
    for(int u:gr[s])
    {
        DFS(u);
    }
}

int main()
{
    
    int vertex,edge;
    cin>>vertex>>edge;

    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        gr[u].push_back(v);
    }
    DFS(1);
    return 0;

}