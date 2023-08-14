#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int temp)
{
    if (st.size() == 0 || st.top() <= temp)
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
    return;
}
void sort_stack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sort_stack(st);
    insert(st, temp);
    // return;
}
int main()
{
    stack<int> st;
    int n, element;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        st.push(element);
    }
    sort_stack(st);
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}