#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int hight[n];
        for (int i = 0; i < n; i++)
        {
            cin >> hight[i];
        }
        int left = 0;
        int right = n - 1;
        int maxHeight = INT_MIN;
        int ai = 0, aj = 0;
        while (left < right)
        {
            if (min(hight[left], hight[right]) > maxHeight)
            {
                maxHeight = min(hight[left], hight[right]);
                ai = left;
                aj = right;
            }
            if (hight[left] < hight[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        cout << ai << " " << aj << endl;
    }
    return 0;
}