#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> G[N];
int main()
{

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (int i = 1; i <= N; i++)
    {

        if (G[i].size() == 0)
            continue;
        cout << i << " : ";
        for (int j : G[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}