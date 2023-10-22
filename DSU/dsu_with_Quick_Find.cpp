#include<bits/stdc++.h>
#define N 10050
using namespace std;

int leader[N];

int find_leader(int u)
{
    return leader[u];
}

void make_union(int len,int u,int v)
{
    int leader_u=find_leader(u);
    int leader_v=find_leader(v);
    if (leader_u!=leader_v)
    {
        for(int i=0;i<len;i++)
        {
            if(leader[i]==leader_v)
            {
                leader[v]=leader_u;
            }
        }
    }
}

int is_connect(int u,int v)
{
    return find_leader(u)==find_leader(v);
}

int main()
{
    int len,U;
    cin>>len>>U;

    for(int i=0;i<len;i++)
    {
        leader[i]=i;
    }
    while(U--)
    {
        int u,v;
        cin>>u>>v;
        make_union(len,u,v);
    }
    int query;
    cin>>query;
    while(query--)
    {
        int u,v;
        cin>>u>>v;
        if(is_connect(u,v)) cout<<"path is connected\n";
        else cout<<"Path is not connected\n";
    }

    return 0;
}