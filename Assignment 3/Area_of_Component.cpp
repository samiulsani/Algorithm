#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m;
char a[N][N];
bool vis[N][N];
vector<pair<int, int>> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

int dfs(int si, int sj)
{
    int room = 1;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
        {
            room += dfs(ci, cj);
        }
    }
    return room;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int minArea = INT_MAX;
    bool foundComponent = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] == '.')
            {
                int availableArea = dfs(i, j);
                minArea = min(minArea, availableArea);
                foundComponent = true;
            }
        }
    }

    if (foundComponent)
    {
        cout << minArea << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}