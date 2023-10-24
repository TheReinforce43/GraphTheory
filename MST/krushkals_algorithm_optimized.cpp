#include <bits/stdc++.h>
#define pi pair<int, int>
#define N 100050
using namespace std;

int leader[N];
int height[N];

void dsu_set(int len)
{
    for (int i = 1; i <= len; i++)
    {
        leader[i] = i;
        height[i] = 0;
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
    if (leaderA == leaderB)
        return;
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
    int vertex, edge;
    cin >> vertex >> edge;
    dsu_set(vertex);
    vector<Edge> edge_list;
    vector<Edge> ans;

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge_list.push_back(Edge(u, v, w));
    }
    sort(edge_list.begin(), edge_list.end(), cmp);

    for (Edge row : edge_list)
    {
        int u = row.u;
        int v = row.v;
        if (find_leader(u) != find_leader(v))
        {
            make_union(u, v);
            ans.push_back(row);
        }
    }
    for (Edge row : ans)
    {
        cout << row.u << " " << row.v << " " << row.w << "\n";
    }

    return 0;
}