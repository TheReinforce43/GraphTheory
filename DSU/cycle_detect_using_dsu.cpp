#include<bits/stdc++.h>
using namespace std;
const int N=10050;
int leader[N];

int find_leader(int u)
{
    if(u==leader[u]) return u;
    return leader[u]=find_leader(leader[u]);
}

void make_union(int u,int v)
{
    int lu=find_leader(u);
    int lv=find_leader(v);
    leader[lv]=lu;
}

bool is_connect(int u,int v)
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
        if(is_connect(u,v))
        {
            cout<<"cycle detected\n";
            return 0;
        } 
        make_union(u,v);
    }
    cout<<"cycle not detected\n";
    return 0;

}