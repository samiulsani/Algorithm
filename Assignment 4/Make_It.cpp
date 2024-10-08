#include <bits/stdc++.h>
using namespace std;

bool make(int n)
{
    vector<bool> dp(n + 1, false);

    dp[0] = true;

    for (int i = 0; i <= n; i++)
    {
        if (dp[i])
        {
            if (i + 3 <= n)
            {
                dp[i + 3] = true;
            }

            if (i * 2 <= n)
            {
                dp[i * 2] = true;
            }
        }
    }
    return dp[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (make(n))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}