#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
typedef pair<int, int> pii;

bool vis[N][N];
int level[N][N];
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int x;

bool isValid(int i, int j)
{
    return ((i >= 0 && i < 8) && (j >= 0 && j < 8));
}

void BFS(int si, int sj)
{
    vis[si][sj] = true;
    level[si][sj] = 0;
    queue<pii> que;
    que.push({si, sj});

    while (!que.empty())
    {
        pii upiar = que.front();
        que.pop();

        int i = upiar.first;
        int j = upiar.second;

        for (pii d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isValid(ni, nj) == false)
                continue;
            if (vis[ni][nj])
                continue;

            que.push({ni, nj});
            level[ni][nj] = level[i][j] + 1;
            vis[ni][nj] = true;
        }
    }
}

void reset_level_vis()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            vis[i][j] = false;
        }
    }
}
int main()
{
    cin >> x;

    int si, sj, di, dj;

    while (x--)
    {
        string Q, R;
        cin >> Q >> R;
        si = Q[0] - 'a';
        sj = Q[1] - '1';
        di = R[0] - 'a';
        dj = R[1] - '1';

        BFS(si, sj);
        cout << level[di][dj] << "\n";

        reset_level_vis();
    }

    return 0;
}