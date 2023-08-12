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

int rod_cut(vector<int> price, int N)
{
    vector<int> length;
    for (int i = 0; i < N; i++)
    {
        length.push_back(i + 1);
    }
    // Matching lenght[] = wt[], price[] = val[], w = N
    // Exactly same problem as unbounded knapsack
    return unbounded_knapsack(length, price, N, N);
}
int main()
{
    int n, e;
    cin >> n;
    vector<int> price;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        price.push_back(e);
    }
    cout << rod_cut(price, n);
    return 0;
}