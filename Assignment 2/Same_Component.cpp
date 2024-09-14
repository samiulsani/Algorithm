#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1005;
bool vis[N][N];
char a[N][N];
bool found = false;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int s1, s2, d1, d2;

bool isValid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.' && !vis[i][j])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    if (si == d1 && sj == d2)
    {
        found = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (isValid(ci, cj) && vis[ci][cj] == false)
        {
            dfs(ci, cj);
        }
    }
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
    cin >> s1 >> s2 >> d1 >> d2;
    memset(vis, false, sizeof(vis));
    dfs(s1, s2);
    if (found)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
