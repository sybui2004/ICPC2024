#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)
#define vi vector<int>
#define vvi vector<vi>


void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    vector<ll> prefix(n+5, 0);

    for (ll &i : a) cin >> i;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    string s;
    cin >> s;
    s = " " + s;
    int check = 0, l = 1, r = s.size();
    while (l < r)
    {
        if (s[l] == 'L' && check == 0)
            check = 1;
        if (s[r] == 'R' && check == 1)
        {
            ans += (prefix[r] - prefix[l - 1]);
            r--;
            l++;
            check = 0;
        }
        if (s[r] != 'R')
            r--;
        if (s[l] != 'L')
            l++;
    }
    cout << ans << "\n";
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