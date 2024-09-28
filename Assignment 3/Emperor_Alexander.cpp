#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int leader[N];
int group_size[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        leader[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (leader[node] == -1)
        return node;
    int l = dsu_find(leader[node]);
    leader[node] = l;
    return l;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (group_size[leaderA] > group_size[leaderB])
        {
            leader[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            leader[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dsu_initialize(n);

    vector<Edge> edgeList;

    for (int i = 0; i < m; i++)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    long long int totalCost = 0;
    long long int edges_cnt = 0;

    for (Edge ed : edgeList)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);
        if (leaderU != leaderV)
        {
            dsu_union(leaderU, leaderV);
            totalCost += ed.w;
            edges_cnt++;
        }
        if (edges_cnt == n - 1)
            break;
    }

    int remove_road = m - edges_cnt;
    if (edges_cnt == n - 1)
    {
        cout << remove_road << " " << totalCost << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}