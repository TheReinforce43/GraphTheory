#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int leader[N];
int height[N];
long long int min_cost = 0;
void init(int len)
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

class row
{
public:
    int u, v, w;
    row(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(row A, row B)
{
    return A.w < B.w;
}

int main()
{

    int vertex, edge;
    cin >> vertex >> edge;
    init(vertex);
    vector<row> edge_list, ans;
    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge_list.push_back(row(u, v, w));
    }

    sort(edge_list.begin(), edge_list.end(), cmp);

    for (row edges : edge_list)
    {
        int u = edges.u;
        int v = edges.v;
        if (find_leader(u) != find_leader(v))
        {
            ans.push_back(edges);
            make_union(u, v);
            min_cost += edges.w;
        }
    }

    cout << min_cost << "\n";
    return 0;
}