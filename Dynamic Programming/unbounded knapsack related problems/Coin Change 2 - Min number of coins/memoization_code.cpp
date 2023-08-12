#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];
int help(vector<int> coins, int amount, int n)
{
    if (amount == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return INT_MAX - 1;
    }
    if (dp[n][amount] != -1)
    {
        return dp[n][amount];
    }
    if (coins[n - 1] <= amount)
    {
        return dp[n][amount] = min(1 + help(coins, amount - coins[n - 1], n), help(coins, amount, n - 1));
    }
    else
    {
        return dp[n][amount] = help(coins, amount, n - 1);
    }
}
int coin_change2(vector<int> coins, int amount, int n)
{
    int ans = help(coins, amount, n);
    if (ans == INT_MAX - 1)
    {
        ans = -1;
    }
    return ans;
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
    memset(dp, -1, sizeof(dp));
    cout << coin_change2(coins, amount, n);
    return 0;
}