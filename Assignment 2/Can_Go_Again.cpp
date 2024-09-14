#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
class Edge
{
public:
    long long int a, b, w;
    Edge(long long int a, long long int b, long long int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a, b, w));
    }
    long long int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    long long int s;
    cin >> s;
    dist[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < EdgeList.size(); j++)
        {
            Edge ed = EdgeList[j];
            long long int u = ed.a;
            long long int EdgeList = ed.b;
            long long int w = ed.w;
            if (dist[u] != INF && dist[EdgeList] > dist[u] + w)
            {
                dist[EdgeList] = dist[u] + w;
            }
        }
    }
    bool neg_cycle = false;
    for (int j = 0; j < EdgeList.size(); j++)
    {
        Edge ed = EdgeList[j];
        long long int u = ed.a;
        long long int EdgeList = ed.b;
        long long int w = ed.w;
        if (dist[u] != INF && dist[EdgeList] > dist[u] + w)
        {
            neg_cycle = true;
            break;
            dist[EdgeList] = dist[u] + w;
        }
    }

    if (neg_cycle == true)
        cout << "Negative Cycle Detected";
    else
    {
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            int d;
            cin >> d;
            if (dist[d] == INF)
                cout << "Not Possible" << endl;
            else
                cout << dist[d] << endl;
        }
    }
    return 0;
}