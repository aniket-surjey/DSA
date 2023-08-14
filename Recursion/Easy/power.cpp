#include <bits/stdc++.h>
using namespace std;

int power(int p, int q)
{
    if (q == 0)
    {
        return 1;
    }

    int ans = power(p, q - 1);
    return (ans * p);
}
int main()
{
    int p, q;
    cin >> p >> q;
    cout << power(p, q);
    return 0;
}