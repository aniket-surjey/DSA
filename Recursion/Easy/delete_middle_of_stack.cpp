#include <bits/stdc++.h>
using namespace std;

void del_mid_stack(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int last_ele = st.top();
    st.pop();
    del_mid_stack(st, k - 1);
    st.push(last_ele);
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
    int k = (n / 2) + 1;
    del_mid_stack(st, k);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}