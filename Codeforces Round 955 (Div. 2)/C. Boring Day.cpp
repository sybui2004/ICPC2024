#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long

void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n+1), dp(n+1, 0);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        dp[i] = dp[i-1] + v[i];
    }

    int pos = 0;
    int cnt = 0;
    while (pos < n)
    {
        auto it = lower_bound(dp.begin() + pos + 1, dp.end(), dp[pos] + l);
        
        if (it == dp.end() || *it > dp[pos] + r)
            pos++;
        else
        {
            cnt++;
            pos = it - dp.begin();
        }
    }
    
    cout << cnt << "\n";
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