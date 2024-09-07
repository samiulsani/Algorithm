//Accepted code
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[1001][1001];
bool vis[1001][1001];
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !vis[i][j]);
}

bool dfs(int si, int sj)
{
    if (a[si][sj] == 'B')
        return true; 
    vis[si][sj] = true;

    for (auto dir : d)
    {
        int ci = si + dir.first;
        int cj = sj + dir.second;

        if (valid(ci, cj))
        {
            if (dfs(ci, cj))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int x, y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    if (dfs(x, y))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}


// Using dfs.............................
#include <bits/stdc++.h>
using namespace std;

// Directions for moving up, down, left, right
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// Grid size and grid itself
int n, m;
char grid[20][20];
bool visited[20][20];

// Validity check for a cell
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !visited[i][j]);
}

// Depth-First Search function
bool dfs(int si, int sj)
{
    if (grid[si][sj] == 'B')
        return true;        // Found room B
    visited[si][sj] = true; // Mark current cell as visited

    // Explore all four possible directions
    for (auto dir : directions)
    {
        int ni = si + dir.first;
        int nj = sj + dir.second;

        if (isValid(ni, nj))
        {
            if (dfs(ni, nj))
                return true; // If we found B in any direction, return true
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;      // Input the grid dimensions
    int startX, startY; // Coordinates of room A

    // Input the grid and find the starting point A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    // Initialize visited array to false
    memset(visited, false, sizeof(visited));

    // Perform DFS starting from room A's coordinates
    if (dfs(startX, startY))
    {
        cout << "YES" << endl; // Output YES if room B is reachable
    }
    else
    {
        cout << "NO" << endl; // Output NO if room B is not reachable
    }

    return 0;
}




// using dfs method 2.......................

#include <bits/stdc++.h>
using namespace std;

// Directions for moving up, down, left, and right
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// Function to check if a cell is within grid bounds and is a floor or target room 'B'
bool isValid(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && (grid[x][y] == '.' || grid[x][y] == 'B'));
}

// DFS function to find if we can reach 'B' from 'A'
bool dfs(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    // If we reached room 'B', return true
    if (grid[x][y] == 'B')
    {
        return true;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Explore all four possible directions
    for (auto [dx, dy] : directions)
    {
        int newX = x + dx;
        int newY = y + dy;
        if (isValid(newX, newY, n, m, grid, visited))
        {
            if (dfs(newX, newY, n, m, grid, visited))
            {
                return true;
            }
        }
    }

    // If all directions are explored and 'B' is not found
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    int startX, startY;

    // Read the grid and locate the start (room 'A') and end (room 'B') positions
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    // Visited matrix to keep track of visited cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Perform DFS from the location of 'A' to see if we can reach 'B'
    if (dfs(startX, startY, n, m, grid, visited))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

// using bfs
#include <bits/stdc++.h>
using namespace std;

// Directions for moving up, down, left, right
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// Grid size and grid itself
int n, m;
char grid[20][20];
bool visited[20][20];

// Validity check for a cell
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !visited[i][j]);
}

// Breadth-First Search function
bool bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        int ci = current.first;
        int cj = current.second;

        // If we reach room B, return true
        if (grid[ci][cj] == 'B')
        {
            return true;
        }

        // Explore all four possible directions
        for (auto dir : directions)
        {
            int ni = ci + dir.first;
            int nj = cj + dir.second;

            if (isValid(ni, nj))
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }

    return false; // If BFS completes without finding room B
}

int main()
{
    cin >> n >> m;      // Input the grid dimensions
    int startX, startY; // Coordinates of room A

    // Input the grid and find the starting point A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    // Initialize visited array to false
    memset(visited, false, sizeof(visited));

    // Perform BFS starting from room A's coordinates
    if (bfs(startX, startY))
    {
        cout << "YES" << endl; // Output YES if room B is reachable
    }
    else
    {
        cout << "NO" << endl; // Output NO if room B is not reachable
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char grid[20][20];
bool visited[20][20];

int n, m;

bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

// Validity check for a cell
// bool isValid(int i, int j)
// {
//     return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !visited[i][j]);
// }

bool bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        int ci = current.first;
        int cj = current.second;

        // If we reach room B, return true
        if (grid[ci][cj] == 'B')
        {
            return true;
        }

        // Explore all four possible directions
        for (auto dir : directions)
        {
            int ni = ci + dir.first;
            int nj = cj + dir.second;

            if (isValid(ni, nj))
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }

    return false; // If BFS completes without finding room B
}

int main()
{
    cin >> n >> m;      // Input the grid dimensions
    int startX, startY; // Coordinates of room A

    // Input the grid and find the starting point A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    // Initialize visited array to false
    memset(visited, false, sizeof(visited));

    // Perform BFS starting from room A's coordinates
    if (bfs(startX, startY))
    {
        cout << "YES" << endl; // Output YES if room B is reachable
    }
    else
    {
        cout << "NO" << endl; // Output NO if room B is not reachable
    }

    return 0;
}


//submitted code


