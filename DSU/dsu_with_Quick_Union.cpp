#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
int leader[N];

int find(int u)
{
    if (leader[u] == u)
        return u;
    return leader[u] = find(leader[u]);
}

void make_union(int u, int v)
{
    int leader_u = find(u);
    int leader_v = find(v);
    leader[leader_v] = leader_u;
}

bool is_connect(int u, int v)
{
    return find(u) == find(v);
}

void init(int len)
{
    for (int i = 0; i < len; i++)
    {
        leader[i] = i;
    }
}

int main()
{
    int len, Quantity_of_elements;
    cin >> len >> Quantity_of_elements;
    init(len);

    while (Quantity_of_elements--)
    {
        int u, v;
        cin >> u >> v;
        make_union(u, v);
    }

    int query;
    cin >> query;
    while (query--)
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