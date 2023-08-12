#include <bits/stdc++.h>
using namespace std;

int LCSubstring(string x, string y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << LCSubstring(x, y, x.size(), y.size());
    return 0;
}