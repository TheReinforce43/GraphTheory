#include <bits/stdc++.h>
using namespace std;

const int N = 10050;
int leader[N];
int leader_size[N];

void dsu_set(int len)
{

    for (int i = 1; i <= len; i++)
    {
        leader[i] = i;
        leader_size[i] = 1;
    }
}

int find_leader(int u)
{
    if (leader[u] == u)
        return u;
    return leader[u] = find_leader(leader[u]);
}

void make_union(int A, int B)
{
    int leaderA = find_leader(A);
    int leaderB = find_leader(B);

    if (leaderA != leaderB)
    {
        if (leader_size[leaderA] > leader_size[leaderB])
        {
            leader[leaderB] = leaderA;
            leader_size[leaderA] += leader_size[leaderB];
        }
        else
        {
            leader[leaderA] = leaderB;
            leader_size[leaderB] += leader_size[leaderA];
        }
    }
}

bool is_connect(int u, int v)
{
    return find_leader(u) == find_leader(v);
}

int main()
{
    int len, U;
    cin >> len >> U;
    dsu_set(len);
    while (U--)
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
            cout << "path is connected\n";
        else
            cout << "path is not connected\n";
    }

    return 0;
}