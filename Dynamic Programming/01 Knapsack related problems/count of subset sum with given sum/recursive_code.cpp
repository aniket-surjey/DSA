#include <bits/stdc++.h>
using namespace std;

int count_subset(vector<int> arr, int sum, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0 && sum != 0)
    {
        return 0;
    }
    if (arr[n - 1] <= sum)
    {
        return count_subset(arr, sum - arr[n - 1], n - 1) + count_subset(arr, sum, n - 1);
    }
    else
    {
        return count_subset(arr, sum, n - 1);
    }
}
int main()
{
    int n, element, sum;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }
    cin >> sum;
    cout << count_subset(arr, sum, n);
    return 0;
}