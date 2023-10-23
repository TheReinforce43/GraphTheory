#include <bits/stdc++.h>

using namespace std;
const int N=2*1e5+50;
int leader[N];
int leader_size[N];
int curr_size = 0;

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
    if (u == leader[u])
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
            curr_size = max(curr_size, leader_size[leaderA]);
        }
        else
        {
            leader[leaderA] = leaderB;
            leader_size[leaderB] += leader_size[leaderA];
            curr_size = max(curr_size, leader_size[leaderB]);
        }
    }
}

int main()
{

    int city, day;
    cin >> city >> day;
    dsu_set(city);
    int cmp = city;
    while (day--)
    {
        int u, v;
        cin >> u >> v;
        if (find_leader(u) != find_leader(v))
        {
            cmp--;
            make_union(u, v);
        }
        cout << cmp << " " << curr_size << "\n";
    }

    return 0;
}