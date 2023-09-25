#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int len = 1005;
int N, M;
vector<string> gr(len);
bool vis[len][len];
int level[len][len];
pair<int, int> parent[len][len];
vector<pair<int, int>> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j)
{
    return ((i >= 0 && i < N) && (j >= 0 && j < M));
}

void BFS(int si, int sj)
{
    queue<pair<int, int>> que;

    que.push({si, sj});

    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!que.empty())
    {
        pair<int, int> upair = que.front();
        que.pop();

        int i = upair.first;
        int j = upair.second;

        for (pair<int, int> d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isValid(ni, nj) == false)
                continue;
            if (vis[ni][nj])
                continue;
            if (gr[ni][nj] == '#')
                continue;

            que.push({ni, nj});
            vis[ni][nj] = true;
            level[ni][nj] = level[i][j] + 1;
            parent[ni][nj] = {i, j};
        }
    }
}

void Direction(vector<pii> path)
{
    for (int i = 1; i < path.size(); i++)
    {
        if (path[i - 1].first == path[i].first)
        {
            if (path[i - 1].second == path[i].second - 1)
                cout << "R";
            else
                cout << "L";
        }
        else
        {
            if (path[i - 1].second == path[i].second)
            {
                if (path[i - 1].first == path[i].first - 1)
                    cout << "D";
                else
                    cout << "U";
            }
        }
    }

    cout << endl;
}

int main()
{

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        gr[i] = str;
    }
    int si, sj, di, dj;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (gr[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (gr[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    BFS(si, sj);

    if (vis[di][dj] == false)
    {
        cout << "NO\n";
        return 0;
    }

    else
        cout << "YES\n";
    cout << level[di][dj] << "\n";

    vector<pair<int, int>> path;

    pair<int, int> curr = {di, dj};

    while (!(curr.first == si && curr.second == sj))
    {
        path.push_back({curr.first, curr.second});
        curr = parent[curr.first][curr.second];
    }
    path.push_back({si, sj});
    reverse(path.begin(), path.end());

    /* for (int i = 0; i < path.size(); i++)
    {
        cout << path[i].first << " " << path[i].second << "\n";
    }
    cout << "\n\n";
     return 0; */

    Direction(path);

    return 0;
}