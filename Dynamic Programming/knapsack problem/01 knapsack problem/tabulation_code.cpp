#include <bits/stdc++.h>
using namespace std;

int dp[102][1002];

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max((val[i - 1] + dp[i - 1][j - wt[i - 1]]), (dp[i - 1][j]));
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
    cout << knapsack(wt, val, w, n);
    return 0;
}