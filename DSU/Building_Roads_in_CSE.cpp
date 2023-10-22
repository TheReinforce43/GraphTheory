#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+50;
int leader[N];
int height[N];
void init(int cities)
{
    for (int i = 1; i <= cities; i++)
    {
        leader[i] = i;
        height[i] = 1;
    }
}
int find_leader(int u)
{
    if (u == leader[u])
        return u;
    return leader[u] = find_leader(leader[u]);
}

void make_union(int u, int v)
{
    int leader_u = find_leader(u);
    int leader_v = find_leader(v);

    if (leader_v != leader_u)
    {
        if (height[leader_u] > height[leader_v])
        {
            leader[leader_v] = leader_u;
        }
        else if (height[leader_u] < height[leader_v])
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

int main()
{
    int cities, roads;
    cin >> cities >> roads;

    init(cities);

    map<int, bool> check;
    vector<int> path;

    while (roads--)
    {
        int u, v;
        cin >> u >> v;
        make_union(u, v);
    }

    for (int i = 1; i <= cities; i++)
    {
        int leader = find_leader(i);
        check[leader] = true;
    }
    for (pair<int, bool> ldr : check)
    {
        path.push_back(ldr.first);
    }
    cout << path.size() - 1 << "\n";

    for (int i = 1; i < path.size(); i++)
    {
        cout << path[i - 1] << " " << path[i] << "\n";
    }

    return 0;
}