#include <bits/stdc++.h>
using namespace std;

string LCS(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < m + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = (1 + dp[i - 1][j - 1]);
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int i = n;
    int j = m;
    string ans;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << LCS(x, y, x.size(), y.size());
    return 0;
}