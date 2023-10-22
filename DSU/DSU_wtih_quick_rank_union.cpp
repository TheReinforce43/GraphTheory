#include <bits/stdc++.h>
using namespace std;
const int N = 10050;

int leader[N];
int height[N];

int find_leader(int u)
{
    if (u == leader[u])
        return u;
    return leader[u] = find_leader(leader[u]);
}

void make_union(int u, int v)
{
    int leader_u = leader[u];
    int leader_v = leader[v];
    if (leader_u != leader_v)
    {
        if (height[u] > height[v])
        {
            leader[leader_v] = leader_u;
        }
        else if (height[u] < height[v])
        {
            leader[leader_u] = leader_v;
        }
        else
        {
            leader[leader_v] = leader_u;
            height[leader_u]++;
        }
    }
}

void init(int len)
{
    for (int i = 1; i <= len; i++)
    {
        leader[i] = i;
        height[i] = 1;
    }
}

bool is_connect(int u, int v)
{
    return find_leader(u) == find_leader(v);
}

int main()
{
    int len, elements;
    cin >> len >> elements;
    init(len);
    while (elements--)
    {
        int u, v;
        cin >> u >> v;
        make_union(u, v);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int u, v;
        cin >> u >> v;
        if (is_connect(u, v))
            cout << "Path is connected\n";
        else
            cout << "Path is not connected\n";
    }

    return 0;
}