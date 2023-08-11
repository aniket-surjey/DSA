#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];
int unbounded_knapsack(vector<int> wt, vector<int> val, int n, int w)
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
        return dp[n][w] = max(val[n - 1] + unbounded_knapsack(wt, val, n, w - wt[n - 1]), unbounded_knapsack(wt, val, n - 1, w));
    }
    else
    {
        return dp[n][w] = unbounded_knapsack(wt, val, n - 1, w);
    }
}
int main()
{
    int n, element;
    cin >> n;
    vector<int> wt;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        wt.push_back(element);
    }
    vector<int> val;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        val.push_back(element);
    }
    int w;
    cin >> w;
    memset(dp, -1, sizeof(dp));
    cout << unbounded_knapsack(wt, val, n, w);
    return 0;
}