#include <bits/stdc++.h>
using namespace std;

int N = 1005;

int main()
{
    int mat[N][N] = {};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (mat[i][j] == 0)
                cout << mat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}