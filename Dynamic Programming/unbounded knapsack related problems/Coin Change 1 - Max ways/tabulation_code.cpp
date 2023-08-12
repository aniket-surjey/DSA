#include <bits/stdc++.h>
using namespace std;

int coin_change1(vector<int> coins, int amount, int n)
{
    int dp[n + 1][amount + 1];
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j < amount + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount];
}
int main()
{
    int n, e;
    cin >> n;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        coins.push_back(e);
    }
    int amount;
    cin >> amount;
    cout << coin_change1(coins, amount, n);
    return 0;
}