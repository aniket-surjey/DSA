#include <bits/stdc++.h>
using namespace std;

int dp[102][1002];

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] <= w)
    {
        return dp[n][w] = max((val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1)), knapsack(wt, val, w, n - 1));
    }
    else if (wt[n - 1] > w)
    {
        return dp[n][w] = knapsack(wt, val, w, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> wt, val;
    int w, element;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        wt.push_back(element);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        val.push_back(element);
    }
    cin >> w;
    memset(dp, -1, sizeof(dp));
    cout << knapsack(wt, val, w, n);
    return 0;
}