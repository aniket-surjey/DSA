#include <bits/stdc++.h>
using namespace std;

int unbounded_knapsack(vector<int> wt, vector<int> val, int n, int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + unbounded_knapsack(wt, val, n, w - wt[n - 1]), unbounded_knapsack(wt, val, n - 1, w));
    }
    else
    {
        return unbounded_knapsack(wt, val, n - 1, w);
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
    cout << unbounded_knapsack(wt, val, n, w);
    return 0;
}