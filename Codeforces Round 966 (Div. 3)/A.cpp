#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

void solve()
{
    string a;
    cin >> a;
    if (a.size() < 3) 
    {
        cout << "NO\n";
        return;
    }
    if (a[0] != '1' || a[1] != '0')
    {
        cout << "NO\n";
        return;
    }

    if (a[2] == '0' || (a[2] == '1' && a.size() == 3))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}