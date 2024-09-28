#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m;
char a[N][N];
bool vis[N][N];
pair<int, int> path[N][N];
pair<int, int> str, dest;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; 

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !vis[i][j]);
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int ci = curr.first + d[i].first;
            int cj = curr.second + d[i].second;

            if (isValid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                path[ci][cj] = curr;
            }
        }
    }
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
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
            if (a[i][j] == 'R')
            {
                str = {i, j};
            }
            else if (a[i][j] == 'D')
            {
                dest = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bfs(str.first, str.second);

    if (!vis[dest.first][dest.second])
    {
        print(); 
    }
    else
    {
        pair<int, int> curr = dest;
        while (curr != str)
        {
            if (a[curr.first][curr.second] != 'D')
            {
                a[curr.first][curr.second] = 'X'; 
            }
            curr = path[curr.first][curr.second];
        }

        print(); 
    }

    return 0;
}
