#include <bits/stdc++.h>
#define N 100
using namespace std;

int root[N];

void init(int len)
{
    for (int i = 0; i < len; i++)
    {
        root[i] = i;
    }
}

int find(int x)
{
    if (x == root[x])
        return x;
    return root[x] = find(root[x]);
}

void Union(int len, int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);

    if (root_x != root_y)
    {
        for (int i = 0; i < len; i++)
        {
            if (root[i] == root_y)
            {
                root[i] = root_x;
            }
        }
    }
}

bool is_connect(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int len;
    cin >> len;
    init(len);
    int U, Q;
    cin >> U;
    while (U--)
    {
        int u, v;
        cin >> u >> v;
        Union(len, u, v);
    }
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