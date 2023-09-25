#include <bits/stdc++.h>
using namespace std;

int N, M;
const int mx = 1005;
bool vis[mx][mx];
vector<string> gr;

bool isValid(int i, int j)
{
    return ((i >= 0 && i < N) && (j >= 0 && j < M));
}

void DFS(int i, int j)
{
    if (vis[i][j])
        return;
    if (isValid(i, j) == false)
        return;
    if (gr[i][j] == '#')
        return;
    vis[i][j] = true;
    DFS(i, j - 1);
    DFS(i, j + 1);
    DFS(i - 1, j);
    DFS(i + 1, j);
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        gr.push_back(str);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (gr[i][j] == '#')
                continue;
            if (vis[i][j])
                continue;
            cnt++;
            DFS(i, j);
        }
    }

    cout << cnt << "\n";

    return 0;
}