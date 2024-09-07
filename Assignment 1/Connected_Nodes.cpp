#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> mat[n];

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        if (mat[n].empty())
        {
            cout << "-1" << endl;
        }
        else
        {

            sort(mat[n].begin(), mat[n].end(), greater<int>());

            for (int x : mat[n])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
