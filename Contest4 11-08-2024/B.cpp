#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << n * n;
        return;
    }

    ll ans = 0;
    for (ll b = k + 1; b <= n; b++)
    {
        ans += (n / b) * (b - k);
        if (n % b >= k)
            ans += (n % b) - k + 1;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}