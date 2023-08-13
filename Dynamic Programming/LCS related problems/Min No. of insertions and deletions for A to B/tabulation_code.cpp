#include <bits/stdc++.h>
using namespace std;

pair<int, int> a_b(string x, string y, int n, int m)
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
    pair<int, int> ans;
    int insert = m - dp[n][m];
    int del = n - dp[n][m];
    ans.first = insert;
    ans.second = del;
    return ans;
}
int main()
{
    string x, y;
    cin >> x >> y;
    pair<int, int> p;
    p = a_b(x, y, x.size(), y.size());
    cout << "Insertions :- " << p.first << " Deletions :- " << p.second;
    return 0;
}