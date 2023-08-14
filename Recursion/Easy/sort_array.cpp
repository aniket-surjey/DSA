#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &arr, int temp)
{
    if (arr.size() == 0 || arr[arr.size() - 1] <= temp)
    {
        arr.push_back(temp);
        return;
    }
    int val = arr[arr.size() - 1];
    arr.pop_back();
    insert(arr, temp);
    arr.push_back(val);
    return;
}
void sort_arr(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return;
    }
    int temp = arr[arr.size() - 1];
    arr.pop_back();
    sort_arr(arr);
    insert(arr, temp);
    // return;
}
int main()
{
    vector<int> arr;
    int n, element;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }
    sort_arr(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}