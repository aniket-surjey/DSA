#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int temp)
{
    if (st.size() == 0)
    {
        st.push(temp);
        return;
    }
    int last_ele = st.top();
    st.pop();
    insert(st, temp);
    st.push(last_ele);
    return;
}
void reverse_stack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverse_stack(st);
    insert(st, temp); // for inserting the element into reversed stack
    return;
}
int main()
{
    stack<int> st;
    int n, e;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        st.push(e);
    }
    reverse_stack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}