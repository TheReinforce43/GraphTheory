#include <bits/stdc++.h>
using namespace std;

int main()
{

    const int N = 100050;

    vector<pair<int, int>> gr[N];

    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    for (int i = 1; i <= vertex; i++)
    {
        if (gr[i].size() == 0)
            continue;
        cout << i << " : ";
        for (pair<int, int> key : gr[i])
        {
            cout << "(" << key.first << "  " << key.second << "), ";
        }
        cout << "\n";
    }

    return 0;
}