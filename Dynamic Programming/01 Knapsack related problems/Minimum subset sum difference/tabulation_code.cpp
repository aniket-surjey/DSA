#include <bits/stdc++.h>
using namespace std;

bool dp[2000][2000];
vector<int> v;
void subset_sum(vector<int> arr, int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < (sum + 1) / 2; j++)
        {
            if (i == n)
            {
                if (dp[i][j] == 1)
                {
                    v.push_back(j);
                }
            }
        }
    }
}

int minimum_subset_sum_difference(vector<int> arr, int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range = range + arr[i];
    }
    subset_sum(arr, range, n);
    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        mn = abs(min(mn, range - 2 * v[i]));
    }
    return mn;
}
int main()
{
    int n, e;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        arr.push_back(e);
    }
    cout << minimum_subset_sum_difference(arr, n);
    return 0;
}