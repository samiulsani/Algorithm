#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long N = 1005;
vector<pair<ll, ll>> v[N];
ll dis[N];
class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(ll src, ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    dis[src] = 0;
    pq.push({src, 0});
    while (!pq.empty())
    {
        pair<ll, ll> parent = pq.top();
        pq.pop();
        ll node = parent.first;
        ll cost = parent.second;

        for (pair<ll, ll> child : v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    ll s;
    cin >> s;
    dijkstra(s, n);
    ll t;
    cin >> t;
    while (t--)
    {
        ll d, dw;
        cin >> d >> dw;

        if (dis[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
