#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long

void solve()
{
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if ((x1-y1) * (x2 - y2) > 0) cout << "YES\n";
    else cout << "NO\n";
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