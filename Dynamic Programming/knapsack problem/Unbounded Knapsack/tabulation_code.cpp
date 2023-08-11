#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];
int unbounded_knapsack(vector<int> wt, vector<int> val, int n, int w)
{
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < w + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
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
    cout << unbounded_knapsack(wt, val, n, w);
    return 0;
}