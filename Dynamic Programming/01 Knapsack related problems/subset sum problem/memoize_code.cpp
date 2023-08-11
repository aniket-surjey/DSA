#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];
bool subset_sum(vector<int> arr, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0 && sum != 0)
    {
        return false;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (arr[n - 1] <= sum)
    {
        return dp[n][sum] = (subset_sum(arr, sum - arr[n - 1], n - 1) || subset_sum(arr, sum, n - 1));
    }
    else
    {
        return dp[n][sum] = subset_sum(arr, sum, n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    int element;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    cout << subset_sum(arr, sum, n);
    return 0;
}