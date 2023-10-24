#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

const int N = 2 * 1e5 + 50;
int leader[N];
vector<pi> gr[N];
bool vis[N];
int height[N];

int min_cost = 0;

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

class edge
{
public:
    int a, b, w;
    edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(edge first, edge second)
    {
        return first.w > second.w;
    }
};
void Krushkal(priority_queue<edge, vector<edge>, cmp> pq)
{
    vector<edge> edge_list;

    while (!pq.empty())
    {
        edge row = pq.top();
        pq.pop();

        int u = row.a;
        int v = row.b;
        int w = row.w;
        if (find_leader(u) != find_leader(v))
        {
            make_union(u, v);
            min_cost += w;
            edge_list.push_back(row);
        }
    }
    for(edge values:edge_list)
    {
        cout<<values.a<<" "<<values.b<<" "<<values.w<<"\n";
    }
}



int main()
{
    int v, e;
    cin >> v >> e;
    dsu_set(v);
    priority_queue<edge, vector<edge>, cmp> pq;

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
        pq.push(edge(u, v, w));
    }
    Krushkal(pq);
    cout << min_cost << "\n";

    return 0;
}