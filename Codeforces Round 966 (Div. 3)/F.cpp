#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)
#define vi vector<int>
#define vvi vector<vi>

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> val(n + 1, vector<ll>(k + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        val[i][0] = 0;
        for (ll p = 1; p <= k; p++)
        {
            val[i][p] = 1e9;
            for (ll r = 0; r <= p; r++)
            {
                ll tmp = p - r;
                if (r > a || tmp > b)
                    continue;
                val[i][p] = min(val[i][p], r * b + tmp * a - r * tmp);
            }
        }
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1e9));
    dp[0][0] = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j <= k; j++)
            for (ll t = j; t <= k; t++)
                dp[i + 1][t] = min(dp[i + 1][t], dp[i][j] + val[i + 1][t - j]);
    

    if (dp[n][k] == 1e9)
        dp[n][k] = -1;
    cout << dp[n][k] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}