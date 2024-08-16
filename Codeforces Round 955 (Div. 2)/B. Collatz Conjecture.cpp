#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    if (x >= y && x < 2 * y && 2 * y - x <= k)
    {
        k -= (2*y-x);
        x = 2;
        if (y == 2) x = 1;
    }
    while (x >= y && k > 0)
    {
        int tmp = x/y;
        int res = (tmp+1)*y;
        if (k > (res - x))
        {
            k -= (res-x);
            x = tmp + 1;
        }else{
            x += k;
            k = 0;
        }
        while (x % y == 0) x/=y;
    }
    if ( k == 0)
    {
        cout << x << "\n";
        return;
    }
    if (y - x <= k)
    {
        k -= (y-x);
        x = 1;
    } 
    
    cout << x + k % (y-1) << "\n";
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
}