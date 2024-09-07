#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (a[i][j] == '#' || vis[i][j])
        return false;
    return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) == true && vis[ci][cj] == false)
        {
            count += dfs(ci, cj);
        }
    }
    return count;
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

    vector<int> apart;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                int count = dfs(i, j);
                apart.push_back(count);
            }
        }
    }

    sort(apart.begin(), apart.end());

    if (apart.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        for (int i = 0; i < apart.size(); i++)
        {
            if (i > 0)
                cout << " ";
            cout << apart[i];
        }
        cout << endl;
    }

    return 0;
}
