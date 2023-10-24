#include <bits/stdc++.h>
#define pi pair<int, int>

using namespace std;
const int N = 2 * 1e5 + 50;
int leader[N];
int height[N];
bool vis[N];
void dsu_set(int len)
{
    for (int i = 1; i <= len; i++)
    {
        height[i] = 0;
        leader[i] = i;
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
        if (height[leaderA] > height[leaderB])
        {
            leader[leaderB] = leaderA;
        }
        else if (height[leaderA] < height[leaderB])
        {
            leader[leaderA] = leaderB;
        }
        else
        {
            leader[leaderB] = leaderA;
            height[leaderA]++;
        }
    }
}

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge A, Edge B)
{
    return A.w < B.w;
}

int main()
{
    int v, e;
    cin >> v >> e;
    dsu_set(v);
    vector<Edge> edges, ans;

    long long int min_cost = 0;
    int cnt = 0;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), cmp);

    for (Edge edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        if (find_leader(u) == find_leader(v))
            continue;
        make_union(u, v);
        ans.push_back(edge);
        cnt++;
        min_cost += (long long int)edge.w;
    }
    if (ans.size()!= (v-1))
    {
        cout << "IMPOSSIBLE\n";
    }
    else
        cout << min_cost << "\n";

    return 0;
}